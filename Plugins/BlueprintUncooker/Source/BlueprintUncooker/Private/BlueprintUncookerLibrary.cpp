#include "BlueprintUncookerLibrary.h"

#include "BlueprintUncookerCore.h"

#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"

#include "AssetRegistry/AssetRegistryModule.h"

#include "Misc/PackageName.h"
#include "HAL/FileManager.h"

// ---------------------------------------------------------------------------
// Public API — thin wrappers around FBlueprintUncookerCore
// ---------------------------------------------------------------------------

FString UBlueprintUncookerLibrary::UncookBlueprintAsset(
	const FString& SourceAssetPath,
	const FString& OutputPath)
{
	return FBlueprintUncookerCore::FormatStatusString(
		FBlueprintUncookerCore::Uncook(SourceAssetPath, OutputPath, /*bChildClass=*/false));
}

FString UBlueprintUncookerLibrary::UncookBlueprintAsChildClass(
	const FString& SourceAssetPath,
	const FString& OutputPath)
{
	return FBlueprintUncookerCore::FormatStatusString(
		FBlueprintUncookerCore::Uncook(SourceAssetPath, OutputPath, /*bChildClass=*/true));
}

FString UBlueprintUncookerLibrary::UncookAllBlueprintsInDirectory(
	const FString& ContentDir,
	const FString& OutputParentDir)
{
	IAssetRegistry& AssetRegistry =
		FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

	FARFilter Filter;
	Filter.PackagePaths.Add(FName(*ContentDir));
	Filter.ClassPaths.Add(UBlueprint::StaticClass()->GetClassPathName());
	Filter.ClassPaths.Add(UBlueprintGeneratedClass::StaticClass()->GetClassPathName());
	Filter.bRecursivePaths      = false;
	Filter.bRecursiveClasses    = true;

	TArray<FAssetData> Assets;
	AssetRegistry.GetAssets(Filter, Assets);

	if (Assets.Num() == 0)
	{
		return FString::Printf(TEXT("No Blueprint assets found in '%s'."), *ContentDir);
	}

	int32 Succeeded = 0;
	int32 Total     = Assets.Num();

	for (const FAssetData& Asset : Assets)
	{
		const FString SourcePath = FBlueprintUncookerCore::SourcePathFromAssetData(Asset);

		FString DerivedOutput;
		if (!OutputParentDir.IsEmpty())
		{
			FString Name = Asset.AssetName.ToString();
			if (Name.EndsWith(TEXT("_C"))) Name.LeftChopInline(2);
			DerivedOutput = OutputParentDir / TEXT("Uncooked") / Name;
		}

		const FBlueprintUncookResult Result =
			FBlueprintUncookerCore::Uncook(SourcePath, DerivedOutput, /*bChildClass=*/false);

		if (!Result.StartsWithError())
		{
			++Succeeded;
		}

		UE_LOG(LogBlueprintUncooker, Log, TEXT("%s → %s"), *SourcePath, *Result.Message);
	}

	return FString::Printf(
		TEXT("Uncook complete: %d/%d succeeded in '%s'."),
		Succeeded, Total, *ContentDir);
}

FString UBlueprintUncookerLibrary::UncookExternalBlueprint(
	const FString& AbsoluteAssetPath,
	const FString& OutputPackagePath,
	const FString& MountPointName,
	const FString& ExternalContentDir)
{
	FString NormalizedPath = FPaths::ConvertRelativePathToFull(AbsoluteAssetPath);
	FPaths::NormalizeFilename(NormalizedPath);

	FString ContentRoot = ExternalContentDir;
	FPaths::NormalizeFilename(ContentRoot);

	if (ContentRoot.IsEmpty())
	{
		FString Dir = FPaths::GetPath(NormalizedPath);
		while (!Dir.IsEmpty())
		{
			if (FPaths::GetBaseFilename(Dir).Equals(TEXT("Content"), ESearchCase::IgnoreCase))
			{
				ContentRoot = Dir;
				break;
			}
			FString Parent = FPaths::GetPath(Dir);
			if (Parent == Dir) break;
			Dir = Parent;
		}
	}

	if (ContentRoot.IsEmpty())
	{
		return FString::Printf(
			TEXT("ERROR: Cannot find a 'Content' directory ancestor in path '%s'. "
			     "Pass ExternalContentDir explicitly."),
			*AbsoluteAssetPath);
	}

	if (!ContentRoot.EndsWith(TEXT("/"))) ContentRoot += TEXT("/");

	FString Mount = MountPointName.IsEmpty() ? TEXT("/ExternalCooked/") : MountPointName;
	if (!Mount.StartsWith(TEXT("/"))) Mount = TEXT("/") + Mount;
	if (!Mount.EndsWith(TEXT("/")))   Mount += TEXT("/");

	FPackageName::RegisterMountPoint(Mount, ContentRoot);

	FString PackageName;
	const bool bConverted = FPackageName::TryConvertFilenameToLongPackageName(
		NormalizedPath, PackageName);

	if (!bConverted)
	{
		FPackageName::UnRegisterMountPoint(Mount, ContentRoot);
		return FString::Printf(
			TEXT("ERROR: TryConvertFilenameToLongPackageName failed. "
			     "Path='%s' ContentRoot='%s' Mount='%s'"),
			*NormalizedPath, *ContentRoot, *Mount);
	}

	UE_LOG(LogBlueprintUncooker, Log,
		TEXT("UncookExternalBlueprint: '%s' → pkg '%s' → out '%s'"),
		*FPaths::GetCleanFilename(AbsoluteAssetPath), *PackageName, *OutputPackagePath);

	const FBlueprintUncookResult Result =
		FBlueprintUncookerCore::Uncook(PackageName, OutputPackagePath, /*bChildClass=*/false);

	FPackageName::UnRegisterMountPoint(Mount, ContentRoot);

	return FBlueprintUncookerCore::FormatStatusString(Result);
}

FString UBlueprintUncookerLibrary::UncookExternalFolder(
	const FString& ExternalContentDir,
	const FString& OutputBase,
	const FString& MountPointName,
	bool bDryRun)
{
	auto IsBlueprintAsset = [](const FString& Filename) -> bool
	{
		static const TCHAR* Prefixes[] = { TEXT("ABP_"), TEXT("BP_"), TEXT("WBP_"), nullptr };
		static const TCHAR* Suffixes[] = { TEXT("_BP"), TEXT("_ABP"), nullptr };
		for (int32 i = 0; Prefixes[i]; ++i)
			if (Filename.StartsWith(Prefixes[i])) return true;
		const FString Base = FPaths::GetBaseFilename(Filename);
		for (int32 i = 0; Suffixes[i]; ++i)
			if (Base.EndsWith(Suffixes[i])) return true;
		return false;
	};

	FString RootDir = ExternalContentDir;
	FPaths::NormalizeFilename(RootDir);
	if (!RootDir.EndsWith(TEXT("/"))) RootDir += TEXT("/");

	TArray<FString> AllFiles;
	IFileManager::Get().FindFilesRecursive(
		AllFiles, *RootDir, TEXT("*.uasset"), /*Files=*/true, /*Dirs=*/false);
	AllFiles.Sort();

	TArray<FString> Blueprints;
	for (const FString& F : AllFiles)
		if (IsBlueprintAsset(FPaths::GetCleanFilename(F)))
			Blueprints.Add(F);

	const int32 Total = Blueprints.Num();
	UE_LOG(LogBlueprintUncooker, Log,
		TEXT("UncookExternalFolder: %d blueprint(s) found in '%s' (DryRun=%s)"),
		Total, *ExternalContentDir, bDryRun ? TEXT("true") : TEXT("false"));

	if (Total == 0)
		return TEXT("0/0 succeeded. No blueprint assets matched the naming filter.");

	const FString EffBase = OutputBase.IsEmpty() ? TEXT("/Game/Uncooked") : OutputBase.TrimEnd();

	int32 Succeeded = 0;
	int32 Failed    = 0;

	for (const FString& AssetPath : Blueprints)
	{
		FString RelPath = AssetPath;
		FPaths::NormalizeFilename(RelPath);
		FPaths::MakePathRelativeTo(RelPath, *RootDir);
		RelPath.ReplaceInline(TEXT("\\"), TEXT("/"));
		FString RelNoExt = FPaths::ChangeExtension(RelPath, TEXT(""));
		FString OutputPkg = EffBase / RelNoExt;
		OutputPkg.ReplaceInline(TEXT("\\"), TEXT("/"));

		if (bDryRun)
		{
			UE_LOG(LogBlueprintUncooker, Log, TEXT("  [DRY] %s  →  %s"),
				*FPaths::GetCleanFilename(AssetPath), *OutputPkg);
			++Succeeded;
			continue;
		}

		const FString R = UncookExternalBlueprint(
			AssetPath, OutputPkg, MountPointName, ExternalContentDir);

		if (R.StartsWith(TEXT("ERROR")))
		{
			++Failed;
			UE_LOG(LogBlueprintUncooker, Warning, TEXT("FAIL  %s — %s"),
				*FPaths::GetCleanFilename(AssetPath), *R);
		}
		else
		{
			++Succeeded;
			UE_LOG(LogBlueprintUncooker, Log, TEXT("OK    %s"),
				*FPaths::GetCleanFilename(AssetPath));
		}
	}

	return FString::Printf(TEXT("%d/%d succeeded."), Succeeded, Total);
}
