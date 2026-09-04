#include "JJKModKitSettingsCustomization.h"

#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "EditorDirectories.h"
#include "IDetailPropertyRow.h"
#include "JJKModKitSettings.h"
#include "Misc/Paths.h"
#include "PropertyHandle.h"
#include "Styling/AppStyle.h"
#include "Widgets/Input/SFilePathPicker.h"

#define LOCTEXT_NAMESPACE "JJKModKitSettingsCustomization"

namespace
{
	const FString GameExeFileTypeFilter(
		TEXT("Executable (*.exe)|*.exe|Jujutsu Kaisen CC.exe|Jujutsu Kaisen CC.exe|All files (*.*)|*.*"));
}

TSharedRef<IDetailCustomization> FJJKModKitSettingsCustomization::MakeInstance()
{
	return MakeShared<FJJKModKitSettingsCustomization>();
}

void FJJKModKitSettingsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TSharedRef<IPropertyHandle> GameExeHandle = DetailBuilder.GetProperty(
		GET_MEMBER_NAME_CHECKED(UJJKModKitSettings, GameExePath));
	GameExeFilePathHandle = GameExeHandle->GetChildHandle(
		GET_MEMBER_NAME_CHECKED(FFilePath, FilePath));

	IDetailCategoryBuilder& CookingCategory = DetailBuilder.EditCategory(TEXT("Cooking"));
	CookingCategory.AddProperty(GameExeHandle)
		.CustomWidget(/*bShowChildren=*/false)
		.NameContent()
		[
			GameExeHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		.MinDesiredWidth(125.0f)
		.MaxDesiredWidth(0.0f)
		[
			SNew(SFilePathPicker)
				.BrowseButtonImage(FAppStyle::GetBrush("PropertyWindow.Button_Ellipsis"))
				.BrowseButtonStyle(FAppStyle::Get(), "HoverHintOnly")
				.BrowseButtonToolTip(LOCTEXT("GameExeBrowseTooltip", "Choose Jujutsu Kaisen CC.exe from this computer"))
				.BrowseDirectory(this, &FJJKModKitSettingsCustomization::GetGameExeBrowseDirectory)
				.BrowseTitle(LOCTEXT("GameExeBrowseTitle", "Select Jujutsu Kaisen CC.exe"))
				.FilePath(this, &FJJKModKitSettingsCustomization::GetGameExePath)
				.FileTypeFilter(GameExeFileTypeFilter)
				.DialogReturnsFullPath(true)
				.OnPathPicked(this, &FJJKModKitSettingsCustomization::OnGameExePathPicked)
		];
}

FString FJJKModKitSettingsCustomization::GetGameExePath() const
{
	FString FilePath;
	if (GameExeFilePathHandle.IsValid())
	{
		GameExeFilePathHandle->GetValue(FilePath);
	}
	return FilePath;
}

FString FJJKModKitSettingsCustomization::GetGameExeBrowseDirectory() const
{
	const FString CurrentPath = FPaths::ConvertRelativePathToFull(GetGameExePath());
	const FString CurrentDir = FPaths::GetPath(CurrentPath);
	if (!CurrentDir.IsEmpty() && FPaths::DirectoryExists(CurrentDir))
	{
		return CurrentDir;
	}
	return FEditorDirectories::Get().GetLastDirectory(ELastDirectory::GENERIC_OPEN);
}

void FJJKModKitSettingsCustomization::OnGameExePathPicked(const FString& PickedPath)
{
	if (!GameExeFilePathHandle.IsValid())
	{
		return;
	}

	const FString AbsolutePath = FPaths::ConvertRelativePathToFull(PickedPath);
	GameExeFilePathHandle->SetValue(AbsolutePath);
	FEditorDirectories::Get().SetLastDirectory(
		ELastDirectory::GENERIC_OPEN, FPaths::GetPath(AbsolutePath));
}

#undef LOCTEXT_NAMESPACE
