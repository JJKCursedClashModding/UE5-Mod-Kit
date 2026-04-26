#include "ModKitDialogLibrary.h"

#if WITH_EDITOR

// ── Slate widget infrastructure ───────────────────────────────────────────────
#include "Framework/Application/SlateApplication.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SWindow.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Input/SSpinBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Views/SListView.h"
#include "Widgets/Views/STableRow.h"
#include "Styling/AppStyle.h"
#include "Misc/MessageDialog.h"

// ─────────────────────────────────────────────────────────────────────────────
// Internal helpers
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Convert a mod title to a safe folder name.
 * Mirrors the Python helper _title_to_folder_name() in new_mod_dialog.py:
 *   - Keeps alpha, digit, underscore, dash
 *   - Collapses whitespace runs to a single underscore
 *   - Strips leading/trailing underscores
 *   - Returns "New_Mod" if the result is empty
 */
static FString TitleToFolderName(const FString& Title)
{
    FString Result;
    bool bPrevWasSpace = false;
    bool bHaveOutput   = false;

    for (const TCHAR Ch : Title)
    {
        const bool bWordChar = FChar::IsAlpha(Ch) || FChar::IsDigit(Ch)
                             || Ch == TEXT('_')    || Ch == TEXT('-');
        const bool bSpace    = FChar::IsWhitespace(Ch);

        if (bWordChar)
        {
            if (bPrevWasSpace && bHaveOutput)
                Result.AppendChar(TEXT('_'));
            Result.AppendChar(Ch);
            bPrevWasSpace = false;
            bHaveOutput   = true;
        }
        else if (bSpace)
        {
            bPrevWasSpace = true;
        }
        // Any other character is silently dropped
    }

    // Strip trailing underscores
    while (Result.Len() > 0 && Result[Result.Len() - 1] == TEXT('_'))
        Result.RemoveAt(Result.Len() - 1, 1, /*bAllowShrinking=*/false);

    return Result.IsEmpty() ? TEXT("New_Mod") : Result;
}

/**
 * Build a horizontally-labelled row: [fixed-width label] [fill-width content].
 * Used by both SModManifestDialog and SModPickerDialog.
 */
static TSharedRef<SWidget> MakeLabeledRow(
    const FText&          Label,
    TSharedRef<SWidget>   Content,
    float                 LabelWidth = 110.f)
{
    return SNew(SHorizontalBox)

        + SHorizontalBox::Slot()
          .AutoWidth()
          .VAlign(VAlign_Center)
          .Padding(FMargin(0.f, 0.f, 10.f, 0.f))
        [
            SNew(SBox)
            .WidthOverride(LabelWidth)
            [
                SNew(STextBlock)
                .Text(Label)
                .Justification(ETextJustify::Right)
            ]
        ]

        + SHorizontalBox::Slot()
          .FillWidth(1.f)
          .VAlign(VAlign_Center)
        [
            Content
        ];
}


// ─────────────────────────────────────────────────────────────────────────────
// SModManifestDialog — form with Title / Description / Version / Priority
// ─────────────────────────────────────────────────────────────────────────────

class SModManifestDialog : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SModManifestDialog)
        : _InitialData()
        , _bIsNew(true)
    {}
        SLATE_ARGUMENT(FModManifestData, InitialData)
        SLATE_ARGUMENT(bool,             bIsNew)
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs)
    {
        bIsNew        = InArgs._bIsNew;
        const FModManifestData& D = InArgs._InitialData;

        TitleText     = FText::FromString(D.Title);
        DescText      = FText::FromString(D.Description);
        VersionText   = FText::FromString(D.Version.IsEmpty() ? TEXT("v1") : D.Version);
        PriorityValue = D.Priority;
        FolderPreview = D.Title.IsEmpty()
            ? FText::FromString(TEXT("(enter a title above)"))
            : FText::FromString(TitleToFolderName(D.Title));

        const FText OkLabel = bIsNew
            ? FText::FromString(TEXT("Create Mod"))
            : FText::FromString(TEXT("Save"));

        ChildSlot
        [
            SNew(SBorder)
            .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
            .Padding(FMargin(16.f))
            [
                SNew(SVerticalBox)

                // ── Title ────────────────────────────────────────────────
                + SVerticalBox::Slot()
                  .AutoHeight()
                  .Padding(FMargin(0.f, 0.f, 0.f, 6.f))
                [
                    MakeLabeledRow(
                        FText::FromString(TEXT("Title")),
                        SNew(SEditableTextBox)
                        .Text(TitleText)
                        .HintText(FText::FromString(TEXT("e.g.  New Yuji Animation")))
                        .MinDesiredWidth(320.f)
                        .OnTextChanged_Lambda([this](const FText& T)
                        {
                            TitleText = T;
                            const FString Trimmed = T.ToString().TrimStartAndEnd();
                            FolderPreview = Trimmed.IsEmpty()
                                ? FText::FromString(TEXT("(enter a title above)"))
                                : FText::FromString(TitleToFolderName(Trimmed));
                        })
                    )
                ]

                // ── Folder name preview (new-mod mode only) ───────────────
                + SVerticalBox::Slot()
                  .AutoHeight()
                  .Padding(FMargin(0.f, 0.f, 0.f, 6.f))
                [
                    SNew(SBox)
                    .Visibility(bIsNew ? EVisibility::Visible : EVisibility::Collapsed)
                    [
                        MakeLabeledRow(
                            FText::FromString(TEXT("Folder name")),
                            SNew(STextBlock)
                            .Text(this, &SModManifestDialog::GetFolderPreview)
                            .ColorAndOpacity(FSlateColor(FLinearColor(0.5f, 0.5f, 0.5f, 1.f)))
                        )
                    ]
                ]

                // ── Description ──────────────────────────────────────────
                + SVerticalBox::Slot()
                  .AutoHeight()
                  .Padding(FMargin(0.f, 0.f, 0.f, 6.f))
                [
                    MakeLabeledRow(
                        FText::FromString(TEXT("Description")),
                        SNew(SBox)
                        .HeightOverride(80.f)
                        [
                            SNew(SMultiLineEditableTextBox)
                            .Text(DescText)
                            .HintText(FText::FromString(TEXT("Short description of what this mod does")))
                            .OnTextChanged_Lambda([this](const FText& T) { DescText = T; })
                        ]
                    )
                ]

                // ── Version ──────────────────────────────────────────────
                + SVerticalBox::Slot()
                  .AutoHeight()
                  .Padding(FMargin(0.f, 0.f, 0.f, 6.f))
                [
                    MakeLabeledRow(
                        FText::FromString(TEXT("Version")),
                        SNew(SBox)
                        .WidthOverride(150.f)
                        [
                            SNew(SEditableTextBox)
                            .Text(VersionText)
                            .HintText(FText::FromString(TEXT("e.g.  v1  or  v2")))
                            .OnTextChanged_Lambda([this](const FText& T) { VersionText = T; })
                        ]
                    )
                ]

                // ── Priority ─────────────────────────────────────────────
                + SVerticalBox::Slot()
                  .AutoHeight()
                  .Padding(FMargin(0.f, 0.f, 0.f, 6.f))
                [
                    MakeLabeledRow(
                        FText::FromString(TEXT("Priority")),
                        SNew(SBox)
                        .WidthOverride(100.f)
                        [
                            SNew(SSpinBox<int32>)
                            .MinValue(TOptional<int32>(-9999))
                            .MaxValue(TOptional<int32>( 9999))
                            .Value(this, &SModManifestDialog::GetPriorityValue)
                            .OnValueChanged_Lambda([this](int32 V) { PriorityValue = V; })
                            .ToolTipText(FText::FromString(
                                TEXT("Higher-priority mods load on top of lower-priority ones "
                                     "when asset names conflict.")))
                        ]
                    )
                ]

                // ── Spacer ────────────────────────────────────────────────
                + SVerticalBox::Slot()
                  .FillHeight(1.f)

                // ── Button row ────────────────────────────────────────────
                + SVerticalBox::Slot()
                  .AutoHeight()
                  .Padding(FMargin(0.f, 12.f, 0.f, 0.f))
                  .HAlign(HAlign_Right)
                [
                    SNew(SHorizontalBox)

                    + SHorizontalBox::Slot()
                      .AutoWidth()
                      .Padding(FMargin(0.f, 0.f, 6.f, 0.f))
                    [
                        SNew(SButton)
                        .Text(OkLabel)
                        .OnClicked(this, &SModManifestDialog::OnOkClicked)
                    ]

                    + SHorizontalBox::Slot()
                      .AutoWidth()
                    [
                        SNew(SButton)
                        .Text(FText::FromString(TEXT("Cancel")))
                        .OnClicked(this, &SModManifestDialog::OnCancelClicked)
                    ]
                ]
            ]
        ];
    }

    // ── Public interface ──────────────────────────────────────────────────────

    bool WasConfirmed() const { return bConfirmed; }

    FModManifestData GetResult() const
    {
        FModManifestData R;
        R.Title        = TitleText.ToString().TrimStartAndEnd();
        R.Description  = DescText.ToString().TrimStartAndEnd();
        R.Version      = VersionText.ToString().TrimStartAndEnd();
        if (R.Version.IsEmpty()) R.Version = TEXT("v1");
        R.Priority     = PriorityValue;
        R.bConfirmed   = bConfirmed;
        return R;
    }

    void SetOwnerWindow(TWeakPtr<SWindow> Win) { OwnerWindow = Win; }

private:
    // ── State ─────────────────────────────────────────────────────────────────
    bool              bIsNew        = true;
    bool              bConfirmed    = false;
    FText             TitleText;
    FText             DescText;
    FText             VersionText;
    int32             PriorityValue = 0;
    FText             FolderPreview;
    TWeakPtr<SWindow> OwnerWindow;

    // ── TAttribute getters ────────────────────────────────────────────────────
    FText GetFolderPreview() const { return FolderPreview; }
    int32 GetPriorityValue() const { return PriorityValue; }

    // ── Window management ─────────────────────────────────────────────────────
    void CloseWindow()
    {
        if (TSharedPtr<SWindow> Win = OwnerWindow.Pin())
            Win->RequestDestroyWindow();
    }

    // ── Button callbacks ──────────────────────────────────────────────────────
    FReply OnOkClicked()
    {
        if (TitleText.ToString().TrimStartAndEnd().IsEmpty())
        {
            FMessageDialog::Open(EAppMsgType::Ok,
                FText::FromString(TEXT("Title must not be empty.")));
            return FReply::Handled();
        }
        bConfirmed = true;
        CloseWindow();
        return FReply::Handled();
    }

    FReply OnCancelClicked()
    {
        CloseWindow();
        return FReply::Handled();
    }
};


// ─────────────────────────────────────────────────────────────────────────────
// SModPickerDialog — listbox for choosing which mod to edit
// ─────────────────────────────────────────────────────────────────────────────

class SModPickerDialog : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SModPickerDialog)
        : _ModNames()
        , _bAddMode(false)
    {}
        SLATE_ARGUMENT(TArray<FString>, ModNames)
        /** When true: shows Add + Cancel only (no Delete button). */
        SLATE_ARGUMENT(bool, bAddMode)
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs)
    {
        bAddMode = InArgs._bAddMode;

        for (const FString& Name : InArgs._ModNames)
            Items.Add(MakeShared<FString>(Name));

        // Button labels / visibility depend on mode
        const FText OkLabel = bAddMode
            ? FText::FromString(TEXT("Add"))
            : FText::FromString(TEXT("Edit"));

        const EVisibility DeleteVisibility = bAddMode
            ? EVisibility::Collapsed
            : EVisibility::Visible;

        ChildSlot
        [
            SNew(SBorder)
            .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
            .Padding(FMargin(16.f))
            [
                SNew(SVerticalBox)

                // Prompt
                + SVerticalBox::Slot()
                  .AutoHeight()
                  .Padding(FMargin(0.f, 0.f, 0.f, 8.f))
                [
                    SNew(STextBlock)
                    .Text(FText::FromString(TEXT("Choose a mod:")))
                ]

                // Listbox
                + SVerticalBox::Slot()
                  .FillHeight(1.f)
                [
                    SAssignNew(ListView, SListView<TSharedPtr<FString>>)
                    .ListItemsSource(&Items)
                    .SelectionMode(ESelectionMode::Single)
                    .OnGenerateRow_Lambda(
                        [](TSharedPtr<FString> Item,
                           const TSharedRef<STableViewBase>& Owner)
                        -> TSharedRef<ITableRow>
                        {
                            return SNew(STableRow<TSharedPtr<FString>>, Owner)
                            [
                                SNew(STextBlock)
                                .Text(FText::FromString(*Item))
                                .Margin(FMargin(4.f, 2.f))
                            ];
                        })
                    .OnMouseButtonDoubleClick_Lambda([this](TSharedPtr<FString> Item)
                    {
                        // Double-click = primary confirm action (Edit or Add)
                        if (Item.IsValid())
                        {
                            ChosenMod = *Item;
                            Action    = bAddMode ? EModPickerAction::Add
                                                 : EModPickerAction::Edit;
                            CloseWindow();
                        }
                    })
                ]

                // ── Button row ───────────────────────────────────────────────
                // Edit/Delete mode:  [ Delete ]  (spacer)  [ Edit ]  [ Cancel ]
                // Add mode:                       (spacer)  [ Add  ]  [ Cancel ]
                + SVerticalBox::Slot()
                  .AutoHeight()
                  .Padding(FMargin(0.f, 12.f, 0.f, 0.f))
                [
                    SNew(SHorizontalBox)

                    // Delete — destructive, left side; hidden in Add mode
                    + SHorizontalBox::Slot()
                      .AutoWidth()
                    [
                        SNew(SBox)
                        .Visibility(DeleteVisibility)
                        [
                            SNew(SButton)
                            .Text(FText::FromString(TEXT("Delete")))
                            .ToolTipText(FText::FromString(
                                TEXT("Permanently delete the selected mod folder.")))
                            .OnClicked(this, &SModPickerDialog::OnDeleteClicked)
                        ]
                    ]

                    // Spacer
                    + SHorizontalBox::Slot()
                      .FillWidth(1.f)

                    // Add / Edit — primary confirm action
                    + SHorizontalBox::Slot()
                      .AutoWidth()
                      .Padding(FMargin(0.f, 0.f, 6.f, 0.f))
                    [
                        SNew(SButton)
                        .Text(OkLabel)
                        .OnClicked(this, &SModPickerDialog::OnOkClicked)
                    ]

                    // Cancel
                    + SHorizontalBox::Slot()
                      .AutoWidth()
                    [
                        SNew(SButton)
                        .Text(FText::FromString(TEXT("Cancel")))
                        .OnClicked(this, &SModPickerDialog::OnCancelClicked)
                    ]
                ]
            ]
        ];

        // Pre-select the first item so pressing the primary button works immediately
        if (Items.Num() > 0)
            ListView->SetSelection(Items[0], ESelectInfo::Direct);
    }

    // ── Public interface ──────────────────────────────────────────────────────

    EModPickerAction GetAction()  const { return Action; }
    FString          GetChosen()  const { return ChosenMod; }

    void SetOwnerWindow(TWeakPtr<SWindow> Win) { OwnerWindow = Win; }

private:
    bool             bAddMode  = false;
    EModPickerAction Action    = EModPickerAction::Cancelled;
    FString          ChosenMod;
    TArray<TSharedPtr<FString>>               Items;
    TSharedPtr<SListView<TSharedPtr<FString>>> ListView;
    TWeakPtr<SWindow>                          OwnerWindow;

    void CloseWindow()
    {
        if (TSharedPtr<SWindow> Win = OwnerWindow.Pin())
            Win->RequestDestroyWindow();
    }

    // ── Add / Edit — primary confirm action ───────────────────────────────────
    FReply OnOkClicked()
    {
        const TArray<TSharedPtr<FString>> Selected = ListView->GetSelectedItems();
        if (Selected.Num() > 0 && Selected[0].IsValid())
        {
            ChosenMod = *Selected[0];
            Action    = bAddMode ? EModPickerAction::Add : EModPickerAction::Edit;
        }
        CloseWindow();
        return FReply::Handled();
    }

    // ── Delete (edit/delete mode only) ────────────────────────────────────────
    FReply OnDeleteClicked()
    {
        const TArray<TSharedPtr<FString>> Selected = ListView->GetSelectedItems();
        if (Selected.Num() == 0 || !Selected[0].IsValid())
            return FReply::Handled();

        const FString ModToDelete = *Selected[0];

        const EAppReturnType::Type Answer = FMessageDialog::Open(
            EAppMsgType::YesNo,
            FText::FromString(FString::Printf(
                TEXT("Permanently delete mod '%s'?\n\n"
                     "This will remove the entire Content/Mods/%s/ folder\n"
                     "and all its contents.  This cannot be undone."),
                *ModToDelete, *ModToDelete
            ))
        );

        if (Answer == EAppReturnType::Yes)
        {
            ChosenMod = ModToDelete;
            Action    = EModPickerAction::Delete;
            CloseWindow();
        }

        return FReply::Handled();
    }

    // ── Cancel ────────────────────────────────────────────────────────────────
    FReply OnCancelClicked()
    {
        CloseWindow();
        return FReply::Handled();
    }
};


// ─────────────────────────────────────────────────────────────────────────────
// UModKitDialogLibrary — exported UFUNCTION implementations
// ─────────────────────────────────────────────────────────────────────────────

FModManifestData UModKitDialogLibrary::ShowModManifestDialog(
    const FModManifestData& InitialData,
    bool bIsNew)
{
    FModManifestData Result = InitialData;
    Result.bConfirmed = false;

    TSharedRef<SModManifestDialog> Content =
        SNew(SModManifestDialog)
        .InitialData(InitialData)
        .bIsNew(bIsNew);

    TSharedRef<SWindow> Window =
        SNew(SWindow)
        .Title(bIsNew
            ? FText::FromString(TEXT("New Mod"))
            : FText::FromString(TEXT("Edit Mod Manifest")))
        .ClientSize(FVector2D(520.f, 300.f))
        .SizingRule(ESizingRule::Autosized)
        .SupportsMinimize(false)
        .SupportsMaximize(false);

    Window->SetContent(Content);
    Content->SetOwnerWindow(Window);

    // AddModalWindow blocks (runs an inner Slate loop) until the window closes.
    FSlateApplication::Get().AddModalWindow(Window, TSharedPtr<SWidget>());

    if (Content->WasConfirmed())
        Result = Content->GetResult();

    return Result;
}

EModPickerAction UModKitDialogLibrary::ShowModPickerDialog(
    const TArray<FString>& ModNames,
    FString& OutChosen)
{
    if (ModNames.Num() == 0)
        return EModPickerAction::Cancelled;

    TSharedRef<SModPickerDialog> Content =
        SNew(SModPickerDialog)
        .ModNames(ModNames)
        .bAddMode(false);

    TSharedRef<SWindow> Window =
        SNew(SWindow)
        .Title(FText::FromString(TEXT("Mod Manager")))
        .ClientSize(FVector2D(340.f, 300.f))
        .SizingRule(ESizingRule::UserSized)
        .SupportsMinimize(false)
        .SupportsMaximize(false);

    Window->SetContent(Content);
    Content->SetOwnerWindow(Window);

    FSlateApplication::Get().AddModalWindow(Window, TSharedPtr<SWidget>());

    const EModPickerAction Action = Content->GetAction();
    if (Action != EModPickerAction::Cancelled)
        OutChosen = Content->GetChosen();

    return Action;
}

EModPickerAction UModKitDialogLibrary::ShowModPickerDialogAdd(
    const TArray<FString>& ModNames,
    FString& OutChosen)
{
    if (ModNames.Num() == 0)
        return EModPickerAction::Cancelled;

    TSharedRef<SModPickerDialog> Content =
        SNew(SModPickerDialog)
        .ModNames(ModNames)
        .bAddMode(true);

    TSharedRef<SWindow> Window =
        SNew(SWindow)
        .Title(FText::FromString(TEXT("Mod Manager")))
        .ClientSize(FVector2D(340.f, 300.f))
        .SizingRule(ESizingRule::UserSized)
        .SupportsMinimize(false)
        .SupportsMaximize(false);

    Window->SetContent(Content);
    Content->SetOwnerWindow(Window);

    FSlateApplication::Get().AddModalWindow(Window, TSharedPtr<SWidget>());

    const EModPickerAction Action = Content->GetAction();
    if (Action == EModPickerAction::Add)
        OutChosen = Content->GetChosen();

    return Action;
}

#else // !WITH_EDITOR  ─────────────────────────────────────────────────────────

FModManifestData UModKitDialogLibrary::ShowModManifestDialog(
    const FModManifestData& InitialData,
    bool /*bIsNew*/)
{
    UE_LOG(LogTemp, Warning,
        TEXT("[JJK Mod Kit] ShowModManifestDialog: editor-only — not available in this build."));
    return InitialData;
}

EModPickerAction UModKitDialogLibrary::ShowModPickerDialog(
    const TArray<FString>& /*ModNames*/,
    FString& /*OutChosen*/)
{
    return EModPickerAction::Cancelled;
}

EModPickerAction UModKitDialogLibrary::ShowModPickerDialogAdd(
    const TArray<FString>& /*ModNames*/,
    FString& /*OutChosen*/)
{
    return EModPickerAction::Cancelled;
}

#endif // WITH_EDITOR
