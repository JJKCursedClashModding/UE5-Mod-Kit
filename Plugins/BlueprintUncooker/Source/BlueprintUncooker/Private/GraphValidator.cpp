#include "GraphValidator.h"

#include "Engine/Blueprint.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"
#include "EdGraph/EdGraphPin.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"

DEFINE_LOG_CATEGORY(LogGraphValidator);

void FGraphValidator::DumpBlueprint(UBlueprint* BP)
{
	if (!BP) return;

	FString Output;
	int32 TotalNodes = 0;
	int32 DisconnectedInputs = 0;
	int32 WildcardConnections = 0;

	// Issues list
	TArray<FString> Issues;

	Output += FString::Printf(TEXT("=== GRAPH DUMP: %s ===\n"), *BP->GetName());
	Output += FString::Printf(TEXT("Parent: %s\n\n"),
		BP->ParentClass ? *BP->ParentClass->GetName() : TEXT("None"));

	TArray<UEdGraph*> AllGraphs;
	BP->GetAllGraphs(AllGraphs);

	for (UEdGraph* Graph : AllGraphs)
	{
		if (!Graph) continue;

		Output += FString::Printf(TEXT("--- GRAPH: %s (%d nodes) ---\n\n"),
			*Graph->GetName(), Graph->Nodes.Num());

		FString GraphIssues;

		int32 NodeIndex = 0;
		for (UEdGraphNode* Node : Graph->Nodes)
		{
			if (!Node) continue;
			++TotalNodes;

			Output += FString::Printf(TEXT("[Node %d] %s @ (%d, %d)\n"),
				NodeIndex++, *Node->GetNodeTitle(ENodeTitleType::FullTitle).ToString(),
				Node->NodePosX, Node->NodePosY);

			FString NodeIssues;

			for (UEdGraphPin* Pin : Node->Pins)
			{
				if (!Pin) continue;

				FString DirStr = (Pin->Direction == EGPD_Input) ? TEXT("In ") : TEXT("Out");
				FString TypeStr = Pin->PinType.PinCategory.ToString();
				if (!Pin->PinType.PinSubCategory.IsNone())
				{
					TypeStr += TEXT("/") + Pin->PinType.PinSubCategory.ToString();
				}

				FString ConnStr;
				if (Pin->LinkedTo.Num() > 0)
				{
					for (UEdGraphPin* Other : Pin->LinkedTo)
					{
						if (Other && Other->GetOwningNode())
						{
							ConnStr += FString::Printf(TEXT("→ %s.%s  "),
								*Other->GetOwningNode()->GetNodeTitle(ENodeTitleType::FullTitle).ToString(),
								*Other->PinName.ToString());
						}
					}
				}
				else
				{
					ConnStr = TEXT("(no link)");
					if (!Pin->DefaultValue.IsEmpty())
					{
						ConnStr += FString::Printf(TEXT(" default=\"%s\""),
							*Pin->DefaultValue);
					}
					else if (Pin->DefaultObject)
					{
						ConnStr += FString::Printf(TEXT(" defaultObj=%s"),
							*Pin->DefaultObject->GetName());
					}
				}

				// Flag disconnected inputs
				bool bDisconnected = false;
				if (Pin->Direction == EGPD_Input
					&& Pin->PinType.PinCategory != TEXT("exec")
					&& Pin->LinkedTo.Num() == 0
					&& Pin->DefaultValue.IsEmpty()
					&& Pin->DefaultObject == nullptr
					&& Pin->DefaultTextValue.IsEmpty())
				{
					++DisconnectedInputs;
					bDisconnected = true;
				}

				// Flag wildcard connections
				bool bWildcard = false;
				if (Pin->PinType.PinCategory == TEXT("wildcard") && Pin->LinkedTo.Num() > 0)
				{
					++WildcardConnections;
					bWildcard = true;
				}

			Output += FString::Printf(TEXT("  [%s] %s [%s] %s%s%s\n"),
				*DirStr, *Pin->PinName.ToString(), *TypeStr, *ConnStr,
				bDisconnected ? TEXT("  *** DISCONNECTED ***") : TEXT(""),
				bWildcard    ? TEXT("  *** WILDCARD ***")      : TEXT(""));

				if (bDisconnected)
				{
					NodeIssues += FString::Printf(TEXT("    [%s]  %s [%s] *** DISCONNECTED ***\n"),
						*DirStr, *Pin->PinName.ToString(), *TypeStr);
				}
			}

			Output += TEXT("\n");

			if (!NodeIssues.IsEmpty())
			{
				GraphIssues += FString::Printf(TEXT("  [Node %d] %s\n"),
					NodeIndex - 1,
					*Node->GetNodeTitle(ENodeTitleType::FullTitle).ToString());
				GraphIssues += NodeIssues;
			}
		}

		if (!GraphIssues.IsEmpty())
		{
			Issues.Add(FString::Printf(TEXT("--- GRAPH: %s (%d nodes)\n%s"),
				*Graph->GetName(), Graph->Nodes.Num(), *GraphIssues));
		}
	}

	// Summary
	Output += TEXT("=== SUMMARY ===\n");
	Output += FString::Printf(TEXT("Total nodes:          %d\n"), TotalNodes);
	Output += FString::Printf(TEXT("Disconnected inputs:  %d\n"), DisconnectedInputs);
	Output += FString::Printf(TEXT("Wildcard connections: %d\n\n"), WildcardConnections);

	if (Issues.Num() > 0)
	{
		Output += TEXT("=== FLAGGED ISSUES ===\n");
		for (const FString& Issue : Issues)
		{
			Output += Issue;
		}
		Output += FString::Printf(TEXT("\nTotal flagged issues: %d\n"), Issues.Num());
	}
	else
	{
		Output += TEXT("=== NO FLAGGED ISSUES ===\n");
	}

	Output += TEXT("=== END DUMP ===\n");

	// Log to output
	UE_LOG(LogGraphValidator, Log, TEXT("\n%s"), *Output);

	// Write to file
	FString SaveDir = FPaths::ProjectSavedDir() / TEXT("BlueprintUncooker");
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (!PlatformFile.DirectoryExists(*SaveDir))
	{
		PlatformFile.CreateDirectoryTree(*SaveDir);
	}

	FString FilePath = SaveDir / FString::Printf(TEXT("%s_dump.txt"), *BP->GetName());
	FFileHelper::SaveStringToFile(Output, *FilePath);

	UE_LOG(LogGraphValidator, Log, TEXT("Graph dump saved to: %s"), *FilePath);
}
