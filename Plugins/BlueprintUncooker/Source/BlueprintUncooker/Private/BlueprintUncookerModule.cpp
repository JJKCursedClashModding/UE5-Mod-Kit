#include "BlueprintUncookerModule.h"
#include "BlueprintUncookerCore.h"

#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"

#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"

#include "Styling/AppStyle.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

#include "Misc/ScopedSlowTask.h"

IMPLEMENT_MODULE(FBlueprintUncookerModule, BlueprintUncooker);

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

static void ShowNotification(const FString& Message, bool bSuccess)
{
	FNotificationInfo Info(FText::FromString(Message));
	Info.ExpireDuration = 5.f;
	Info.bFireAndForget = true;
	Info.Image = FAppStyle::GetBrush(bSuccess ? TEXT("NotificationList.SuccessImage")
	                                           : TEXT("NotificationList.FailImage"));
	FSlateNotificationManager::Get().AddNotification(Info);
}

// ---------------------------------------------------------------------------
// Module lifecycle
// ---------------------------------------------------------------------------

void FBlueprintUncookerModule::StartupModule()
{
	FContentBrowserModule& CBM =
		FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

	TArray<FContentBrowserMenuExtender_SelectedAssets>& Extenders =
		CBM.GetAllAssetViewContextMenuExtenders();

	Extenders.Add(FContentBrowserMenuExtender_SelectedAssets::CreateRaw(
		this, &FBlueprintUncookerModule::ExtendContentBrowserMenu));

	ContentBrowserExtenderHandle = Extenders.Last().GetHandle();
}

void FBlueprintUncookerModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("ContentBrowser"))
	{
		FContentBrowserModule& CBM =
			FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");

		TArray<FContentBrowserMenuExtender_SelectedAssets>& Extenders =
			CBM.GetAllAssetViewContextMenuExtenders();

		Extenders.RemoveAll([this](const FContentBrowserMenuExtender_SelectedAssets& E)
		{
			return E.GetHandle() == ContentBrowserExtenderHandle;
		});
	}

	LiveUncookedBPs.Empty();
}

// ---------------------------------------------------------------------------
// Content Browser menu extension
// ---------------------------------------------------------------------------

TSharedRef<FExtender> FBlueprintUncookerModule::ExtendContentBrowserMenu(
	const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	bool bAnyBlueprint = false;
	for (const FAssetData& Asset : SelectedAssets)
	{
		const FString ClassPath = Asset.AssetClassPath.ToString();
		if (ClassPath.Contains(TEXT("Blueprint")) || ClassPath.EndsWith(TEXT("_C")))
		{
			bAnyBlueprint = true;
			break;
		}
		if (UObject* Obj = Asset.FastGetAsset(false))
		{
			if (Obj->IsA<UBlueprint>() || Obj->IsA<UBlueprintGeneratedClass>())
			{
				bAnyBlueprint = true;
				break;
			}
		}
	}

	if (!bAnyBlueprint)
	{
		return Extender;
	}

	Extender->AddMenuExtension(
		"GetAssetActions",
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateLambda([this, SelectedAssets](FMenuBuilder& MenuBuilder)
		{
			MenuBuilder.AddMenuEntry(
				FText::FromString(TEXT("Uncook Blueprint")),
				FText::FromString(TEXT("Reconstruct an editable Blueprint from cooked bytecode.")),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.Blueprint"),
				FUIAction(FExecuteAction::CreateRaw(
					this, &FBlueprintUncookerModule::ExecuteUncookBlueprint, SelectedAssets))
			);

			MenuBuilder.AddMenuEntry(
				FText::FromString(TEXT("Uncook as Child Class (PIE Test)")),
				FText::FromString(TEXT("Create a child Blueprint whose parent is the cooked class. Casts succeed via inheritance.")),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.Blueprint"),
				FUIAction(FExecuteAction::CreateRaw(
					this, &FBlueprintUncookerModule::ExecuteLiveUncook, SelectedAssets))
			);
		})
	);

	return Extender;
}

// ---------------------------------------------------------------------------
// Mode A: Standard uncook
// ---------------------------------------------------------------------------

void FBlueprintUncookerModule::ExecuteUncookBlueprint(TArray<FAssetData> SelectedAssets)
{
	FScopedSlowTask Progress(
		(float)SelectedAssets.Num(),
		FText::FromString(TEXT("Uncoooking Blueprints...")));
	Progress.MakeDialog(true);

	int32 Successes = 0;

	for (const FAssetData& Asset : SelectedAssets)
	{
		if (Progress.ShouldCancel()) break;
		Progress.EnterProgressFrame(1.f, FText::FromString(Asset.AssetName.ToString()));

		const FString SourcePath = FBlueprintUncookerCore::SourcePathFromAssetData(Asset);
		const FString OutputPath = FBlueprintUncookerCore::DeriveOutputPath(SourcePath, TEXT(""));

		const FBlueprintUncookResult Result =
			FBlueprintUncookerCore::Uncook(SourcePath, OutputPath, /*bChildClass=*/false);

		if (Result.StartsWithError())
		{
			UE_LOG(LogBlueprintUncooker, Warning, TEXT("Uncook failed for %s: %s"),
				*Asset.AssetName.ToString(), *Result.Message);
			continue;
		}

		UE_LOG(LogBlueprintUncooker, Log, TEXT("Uncooked %s → %s (%s)"),
			*SourcePath, *OutputPath, *Result.Message);
		++Successes;
	}

	ShowNotification(
		FString::Printf(TEXT("Uncook complete: %d/%d succeeded"), Successes, SelectedAssets.Num()),
		Successes > 0);
}

// ---------------------------------------------------------------------------
// Mode B: Live / child-class uncook
// ---------------------------------------------------------------------------

void FBlueprintUncookerModule::ExecuteLiveUncook(TArray<FAssetData> SelectedAssets)
{
	for (const FAssetData& Asset : SelectedAssets)
	{
		const FString SourcePath = FBlueprintUncookerCore::SourcePathFromAssetData(Asset);

		FString ChildName = FPackageName::GetLongPackageAssetName(SourcePath);
		ChildName += TEXT("_Uncook");
		const FString OutputPath =
			FPackageName::GetLongPackagePath(SourcePath) / TEXT("Uncooked") / ChildName;

		const FBlueprintUncookResult Result =
			FBlueprintUncookerCore::Uncook(SourcePath, OutputPath, /*bChildClass=*/true);

		if (Result.StartsWithError())
		{
			UE_LOG(LogBlueprintUncooker, Warning, TEXT("Live uncook failed for %s: %s"),
				*Asset.AssetName.ToString(), *Result.Message);
			continue;
		}

		if (Result.CreatedBlueprint)
		{
			LiveUncookedBPs.Add(Result.CreatedBlueprint);
		}

		UE_LOG(LogBlueprintUncooker, Log,
			TEXT("Live-uncooked child BP: %s. Set your GameMode to use this class, then PIE."),
			*ChildName);

		ShowNotification(
			FString::Printf(TEXT("Child class '%s' created. Set GameMode and PIE."), *ChildName),
			true);
	}
}
