#pragma once

#include "IDetailCustomization.h"
#include "Templates/SharedPointer.h"

class IPropertyHandle;

/**
 * Replaces the stock FFilePath picker for Game Exe Path.
 *
 * UE 5.1's default picker does not set DialogReturnsFullPath, so Windows
 * OpenFileDialog rewrites the selection relative to Engine/Binaries/Win64.
 * That conversion cannot represent a file on another drive.
 */
class FJJKModKitSettingsCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();

	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	FString GetGameExePath() const;
	FString GetGameExeBrowseDirectory() const;
	void OnGameExePathPicked(const FString& PickedPath);

	TSharedPtr<IPropertyHandle> GameExeFilePathHandle;
};
