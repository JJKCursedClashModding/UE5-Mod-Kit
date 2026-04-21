#include "MontageBridgeLibrary.h"
#include "Animation/AnimMontage.h"            // UAnimMontage, FSlotAnimationTrack, FCompositeSection
#include "Animation/AnimLinkableElement.h"    // FAnimLinkableElement — StaticStruct() for reflection
#include "Animation/AnimNotifies/AnimNotify.h"      // UAnimNotify      — DuplicateObject
#include "Animation/AnimNotifies/AnimNotifyState.h" // UAnimNotifyState — DuplicateObject
#include "Animation/AnimSequence.h"           // UAnimSequence::GetSamplingFrameRate()
#if WITH_EDITOR
#include "Animation/AnimData/AnimDataModel.h"       // UAnimDataModel — direct field write via reflection
#include "ContentBrowserModule.h"                   // FContentBrowserModule
#include "IContentBrowserSingleton.h"               // IContentBrowserSingleton::GetSelectedFolders()
#include "ContentBrowserDataMenuContexts.h"         // UContentBrowserDataMenuContext_FolderMenu
#include "ContentBrowserItem.h"                     // FContentBrowserItem::GetInternalPath()
#endif

// ---------------------------------------------------------------------------
// Internal helpers
// ---------------------------------------------------------------------------

// Read a protected float field from an FAnimLinkableElement via reflection.
static float GetLinkValue(const FAnimLinkableElement& Element)
{
    static FFloatProperty* Prop = CastField<FFloatProperty>(
        FAnimLinkableElement::StaticStruct()->FindPropertyByName(TEXT("LinkValue")));
    return Prop ? Prop->GetPropertyValue_InContainer(&Element) : -999.f;
}

// Remap the protected LinkedMontage field when it currently points to Source.
// Null entries (LinkedMontage == nullptr) are left untouched.
static void FixupLinkedMontage(FAnimLinkableElement& Element,
                               UAnimMontage* Source,
                               UAnimMontage* NewMontage)
{
    static FObjectPropertyBase* Prop = CastField<FObjectPropertyBase>(
        FAnimLinkableElement::StaticStruct()->FindPropertyByName(TEXT("LinkedMontage")));

    if (!ensureMsgf(Prop,
        TEXT("[JJK Mod Kit] FixupLinkedMontage: LinkedMontage property not found")))
        return;

    UObject* Current = Prop->GetObjectPropertyValue_InContainer(&Element);
    if (Current == Source)
        Prop->SetObjectPropertyValue_InContainer(&Element, NewMontage);
    // nullptr → leave null; anything else → leave unchanged
}

// ---------------------------------------------------------------------------
// CopyMontageData
// ---------------------------------------------------------------------------
void UMontageBridgeLibrary::CopyMontageData(UAnimMontage* Source, UAnimMontage* Dest)
{
    if (!IsValid(Source) || !IsValid(Dest))
    {
        UE_LOG(LogTemp, Warning, TEXT("[JJK Mod Kit] CopyMontageData: null Source or Dest — aborting."));
        return;
    }

    // ── 1. Clear Dest arrays (ensures no leftover default-init data) ───────────
    Dest->SlotAnimTracks.Reset();
    Dest->CompositeSections.Reset();
    Dest->Notifies.Reset();
    Dest->AnimNotifyTracks.Reset();

    // ── 2. SlotAnimTracks ──────────────────────────────────────────────────────
    Dest->SlotAnimTracks = Source->SlotAnimTracks;

    // ── 3. CompositeSections ───────────────────────────────────────────────────
    Dest->CompositeSections = Source->CompositeSections;
    for (FCompositeSection& Section : Dest->CompositeSections)
        FixupLinkedMontage(Section, Source, Dest);

    // ── 4. Notifies — deep copy ────────────────────────────────────────────────
    Dest->Notifies = Source->Notifies;
    UPackage* SrcPackage = Source->GetOutermost();
    for (FAnimNotifyEvent& Event : Dest->Notifies)
    {
        if (Event.Notify && Event.Notify->GetOutermost() == SrcPackage)
            Event.Notify = DuplicateObject<UAnimNotify>(Event.Notify, Dest);
        if (Event.NotifyStateClass && Event.NotifyStateClass->GetOutermost() == SrcPackage)
            Event.NotifyStateClass = DuplicateObject<UAnimNotifyState>(Event.NotifyStateClass, Dest);
        FixupLinkedMontage(Event,         Source, Dest);
        FixupLinkedMontage(Event.EndLink, Source, Dest);
    }

    // ── 5. AnimNotifyTracks ────────────────────────────────────────────────────
    Dest->AnimNotifyTracks = Source->AnimNotifyTracks;

    // ── 6. Scalar / struct properties ─────────────────────────────────────────
    Dest->BlendIn             = Source->BlendIn;
    Dest->BlendOut            = Source->BlendOut;
    Dest->RateScale           = Source->RateScale;
    Dest->bEnableAutoBlendOut = Source->bEnableAutoBlendOut;
    Dest->BlendOutTriggerTime = Source->BlendOutTriggerTime;

    // ── 7. SequenceLength + AnimDataModel ──────────────────────────────────────
    // MUST be done BEFORE RefreshCacheData() for two reasons:
    //   (a) SequenceLength > 0 → SnapNotifiesAndSections doesn't clamp all
    //       notifies to t=0 when the montage is saved / PostLoad'd.
    //   (b) DataModel.FrameRate is correct when RefreshCacheData computes
    //       TriggerTimeOffset for each notify.
    //
    // We bypass IAnimationDataController entirely — its SetPlayLength/SetFrameRate
    // methods fire SequenceLengthChanged/FrameRateChanged which rescale every
    // notify's LinkValue and corrupt the timing data we just copied.
    // Direct property-reflection writes are safe (no callbacks fired).
    {
        // Use 30 fps as the DataModel display rate.
        // The ×1000 over-sampled rate (60000 fps) caused the editor preview to run
        // the animation at the wrong speed.  30 fps matches the JJK montage display
        // rate and produces correct playback speed in the Montage editor preview.
        FFrameRate SamplingRate(30, 1);

        const float PlayLength = Source->GetPlayLength();
        const int32 NumFrames  = FMath::RoundToInt(PlayLength * SamplingRate.AsDecimal());
        const int32 NumKeys    = NumFrames + 1;

        // Set the montage's own SequenceLength (separate from DataModel->PlayLength).
        // This is the field GetPlayLength() and the editor timeline both read.
        // Field is deprecated in 5.2+ but still the correct write path in 5.1.
        PRAGMA_DISABLE_DEPRECATION_WARNINGS
        Dest->SequenceLength = PlayLength;
        PRAGMA_ENABLE_DEPRECATION_WARNINGS

#if WITH_EDITOR
        if (UAnimDataModel* Model = Dest->GetDataModel())
        {
            UClass* MC = UAnimDataModel::StaticClass();

            if (FFloatProperty* P = CastField<FFloatProperty>(
                    MC->FindPropertyByName(TEXT("PlayLength"))))
                P->SetPropertyValue_InContainer(Model, PlayLength);

            if (FIntProperty* P = CastField<FIntProperty>(
                    MC->FindPropertyByName(TEXT("NumberOfFrames"))))
                P->SetPropertyValue_InContainer(Model, NumFrames);

            if (FIntProperty* P = CastField<FIntProperty>(
                    MC->FindPropertyByName(TEXT("NumberOfKeys"))))
                P->SetPropertyValue_InContainer(Model, NumKeys);

            if (FStructProperty* P = CastField<FStructProperty>(
                    MC->FindPropertyByName(TEXT("FrameRate"))))
            {
                if (FFrameRate* FR = P->ContainerPtrToValuePtr<FFrameRate>(Model))
                    *FR = SamplingRate;
            }

            UE_LOG(LogTemp, Log,
                TEXT("[JJK Mod Kit] AnimDataModel: PlayLength=%.4f  FrameRate=%d/%d  "
                     "NumFrames=%d  NumKeys=%d  Montage.SequenceLength=%.4f"),
                PlayLength,
                SamplingRate.Numerator, SamplingRate.Denominator,
                Model->GetNumberOfFrames(), Model->GetNumberOfKeys(),
                Dest->GetPlayLength());
        }
#endif
    }

    // ── 8. Rebuild caches (AFTER DataModel and SequenceLength are set) ─────────
    Dest->RefreshCacheData();

    Dest->MarkPackageDirty();

    UE_LOG(LogTemp, Log,
        TEXT("[JJK Mod Kit] CopyMontageData: %s → %s  slots=%d  sections=%d  notifies=%d  tracks=%d"),
        *Source->GetPathName(), *Dest->GetPathName(),
        Dest->SlotAnimTracks.Num(), Dest->CompositeSections.Num(),
        Dest->Notifies.Num(), Dest->AnimNotifyTracks.Num());
}

// ---------------------------------------------------------------------------
// LogNotifyTimes
// ---------------------------------------------------------------------------
void UMontageBridgeLibrary::LogNotifyTimes(UAnimMontage* Montage)
{
    if (!IsValid(Montage))
    {
        UE_LOG(LogTemp, Warning, TEXT("[JJK Mod Kit] LogNotifyTimes: null Montage"));
        return;
    }

    UE_LOG(LogTemp, Log,
        TEXT("[JJK Mod Kit] LogNotifyTimes: %s  notifies=%d"),
        *Montage->GetPathName(), Montage->Notifies.Num());

    for (int32 i = 0; i < Montage->Notifies.Num(); ++i)
    {
        const FAnimNotifyEvent& E = Montage->Notifies[i];
        UE_LOG(LogTemp, Log,
            TEXT("[JJK Mod Kit]   [POST-RENAME] Notify[%d] '%s'  GetTime=%.6f  LinkedMontage=%s"),
            i, *E.NotifyName.ToString(),
            E.GetTime(EAnimLinkMethod::Absolute),
            E.GetLinkedMontage() ? *E.GetLinkedMontage()->GetName() : TEXT("null"));
    }
}

// ---------------------------------------------------------------------------
// GetSelectedFolderPaths
// ---------------------------------------------------------------------------
TArray<FString> UMontageBridgeLibrary::GetSelectedFolderPaths()
{
    TArray<FString> Paths;
#if WITH_EDITOR
    if (FModuleManager::Get().IsModuleLoaded(TEXT("ContentBrowser")))
    {
        IContentBrowserSingleton& ContentBrowser =
            FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser")).Get();
        ContentBrowser.GetSelectedFolders(Paths);
    }
    else
    {
        UE_LOG(LogTemp, Warning,
            TEXT("[JJK Mod Kit] GetSelectedFolderPaths: ContentBrowser module not loaded."));
    }
#endif
    return Paths;
}

// ---------------------------------------------------------------------------
// GetFolderPathsFromToolMenuContext
// ---------------------------------------------------------------------------
TArray<FString> UMontageBridgeLibrary::GetFolderPathsFromToolMenuContext(
    const FToolMenuContext& Context)
{
    TArray<FString> Paths;
#if WITH_EDITOR
    // FindContext<T>() iterates Context.ContextObjects (private UPROPERTY) and
    // casts each entry to T — this is the canonical way to extract typed context
    // data in C++.  Python has no equivalent because neither FindByClass() nor
    // ContextObjects is a UFUNCTION/BlueprintReadOnly.
    if (const UContentBrowserDataMenuContext_FolderMenu* FolderCtx =
            Context.FindContext<UContentBrowserDataMenuContext_FolderMenu>())
    {
        for (const FContentBrowserItem& Item : FolderCtx->SelectedItems)
        {
            // GetInternalPath() returns the package-style path like "/Game/Foo/Bar".
            const FName InternalPath = Item.GetInternalPath();
            if (!InternalPath.IsNone())
            {
                Paths.Add(InternalPath.ToString());
                continue;
            }
            // Fallback: virtual path (may include source-control prefixes).
            const FName VirtualPath = Item.GetVirtualPath();
            if (!VirtualPath.IsNone())
            {
                Paths.Add(VirtualPath.ToString());
            }
        }
    }
    else
    {
        // Log at verbose so it doesn't spam when this is called from non-folder menus.
        UE_LOG(LogTemp, Verbose,
            TEXT("[JJK Mod Kit] GetFolderPathsFromToolMenuContext: "
                 "UContentBrowserDataMenuContext_FolderMenu not found in context."));
    }
#endif
    return Paths;
}

// ---------------------------------------------------------------------------
// DumpMontageDebugInfo
// ---------------------------------------------------------------------------
void UMontageBridgeLibrary::DumpMontageDebugInfo(UAnimMontage* Montage)
{
    if (!IsValid(Montage))
    {
        UE_LOG(LogTemp, Warning, TEXT("[JJK Mod Kit] DumpMontageDebugInfo: null Montage"));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("================================================== [JJK Mod Kit] DumpMontageDebugInfo"));
    UE_LOG(LogTemp, Log, TEXT("  Path           : %s"), *Montage->GetPathName());
    UE_LOG(LogTemp, Log, TEXT("  SequenceLength : %.6f"), Montage->GetPlayLength());
    UE_LOG(LogTemp, Log, TEXT("  RateScale      : %.4f"), Montage->RateScale);

    // SlotAnimTracks
    UE_LOG(LogTemp, Log, TEXT("  SlotAnimTracks : %d"), Montage->SlotAnimTracks.Num());
    for (int32 i = 0; i < Montage->SlotAnimTracks.Num(); ++i)
    {
        const FSlotAnimationTrack& T = Montage->SlotAnimTracks[i];
        UE_LOG(LogTemp, Log, TEXT("    Slot[%d] Name=%s  Segments=%d"),
            i, *T.SlotName.ToString(), T.AnimTrack.AnimSegments.Num());
        for (int32 j = 0; j < T.AnimTrack.AnimSegments.Num(); ++j)
        {
            const FAnimSegment& Seg = T.AnimTrack.AnimSegments[j];
            UE_LOG(LogTemp, Log,
                TEXT("      Seg[%d]  Ref=%-40s  StartPos=%.4f  AnimStart=%.4f  AnimEnd=%.4f"),
                j,
                Seg.GetAnimReference() ? *Seg.GetAnimReference()->GetName() : TEXT("null"),
                Seg.StartPos, Seg.AnimStartTime, Seg.AnimEndTime);
        }
    }

#if WITH_EDITOR
    // AnimDataModel
    UE_LOG(LogTemp, Log, TEXT("  --- AnimDataModel ---"));
    if (const UAnimDataModel* Model = Montage->GetDataModel())
    {
        // Read FrameRate via reflection (protected field)
        FFrameRate FR(0, 1);
        if (FStructProperty* P = CastField<FStructProperty>(
                UAnimDataModel::StaticClass()->FindPropertyByName(TEXT("FrameRate"))))
        {
            if (const FFrameRate* Ptr = P->ContainerPtrToValuePtr<FFrameRate>(
                    const_cast<UAnimDataModel*>(Model)))
                FR = *Ptr;
        }
        UE_LOG(LogTemp, Log, TEXT("    PlayLength     = %.6f"), Model->GetPlayLength());
        UE_LOG(LogTemp, Log, TEXT("    FrameRate      = %d/%d  (%.2f fps)"),
            FR.Numerator, FR.Denominator,
            FR.Denominator > 0 ? (float)FR.Numerator / FR.Denominator : 0.f);
        UE_LOG(LogTemp, Log, TEXT("    NumberOfFrames = %d"), Model->GetNumberOfFrames());
        UE_LOG(LogTemp, Log, TEXT("    NumberOfKeys   = %d"), Model->GetNumberOfKeys());
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("    (null — no DataModel attached)"));
    }
#endif

    // Notifies
    UE_LOG(LogTemp, Log, TEXT("  --- Notifies (%d) ---"), Montage->Notifies.Num());
    for (int32 i = 0; i < Montage->Notifies.Num(); ++i)
    {
        const FAnimNotifyEvent& E = Montage->Notifies[i];
        const float LinkValue = GetLinkValue(E);
        UE_LOG(LogTemp, Log,
            TEXT("  [%2d] %-40s  LinkValue=%.6f  GetTime=%.6f  TTO=%.6f  TriggerTime=%.6f  LM=%s"),
            i, *E.NotifyName.ToString(),
            LinkValue,
            E.GetTime(EAnimLinkMethod::Absolute),
            E.TriggerTimeOffset,
            E.GetTriggerTime(),
            E.GetLinkedMontage() ? *E.GetLinkedMontage()->GetName() : TEXT("null"));
    }
    UE_LOG(LogTemp, Log, TEXT("=================================================="));
}
