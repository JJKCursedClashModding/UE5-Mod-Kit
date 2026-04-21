#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class UBlueprint;
struct FAssetData;
class FExtender;

DECLARE_LOG_CATEGORY_EXTERN(LogBlueprintUncooker, Log, All);

class FBlueprintUncookerModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedRef<FExtender> ExtendContentBrowserMenu(const TArray<FAssetData>& SelectedAssets);
	void ExecuteUncookBlueprint(TArray<FAssetData> SelectedAssets);
	void ExecuteLiveUncook(TArray<FAssetData> SelectedAssets);

	/** Resolves the UBlueprintGeneratedClass from an arbitrary asset (Blueprint, BPGC, or raw UClass). */
	class UBlueprintGeneratedClass* ResolveGeneratedClass(const FAssetData& Asset);

	FDelegateHandle ContentBrowserExtenderHandle;

	/** Keeps live-uncooked BPs from being GC'd during the editor session. */
	TArray<UBlueprint*> LiveUncookedBPs;
};
