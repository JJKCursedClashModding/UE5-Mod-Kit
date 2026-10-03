#include "SequencerTrackBase.h"

#include "Compilation/IMovieSceneTrackTemplateProducer.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "MovieSceneSection.h"
#include "SequencerEvaluateBase.h"

USequencerTrackBase::USequencerTrackBase(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
}

FMovieSceneEvalTemplatePtr USequencerTrackBase::CreateTemplateForSection(const UMovieSceneSection& InSection) const {
    UClass* SectionClass = InSection.GetClass();
    if (!SectionClass) {
        return FMovieSceneEvalTemplatePtr();
    }

    // The game declares a USTRUCT evaluation template per section class. UHT strips the leading
    // U/F from object names, so the script object names are:
    //   U<Name>Section  ->  <Name>Section     F<Name>Evaluate  ->  <Name>Evaluate
    FString BaseName = SectionClass->GetName();
    if (!BaseName.RemoveFromEnd(TEXT("Section"))) {
        return FMovieSceneEvalTemplatePtr();
    }

    // Derive the script module path from the class path ("/Script/Module.Class").
    const FString ClassPath = SectionClass->GetPathName();
    int32 DotIndex = INDEX_NONE;
    const FString PackagePath = ClassPath.FindChar(TEXT('.'), DotIndex)
        ? ClassPath.Left(DotIndex)
        : SectionClass->GetOutermost()->GetName();

    const FString StructPath = FString::Printf(TEXT("%s.%sEvaluate"), *PackagePath, *BaseName);
    UScriptStruct* EvalStruct = FindObject<UScriptStruct>(nullptr, *StructPath);
    if (!EvalStruct || !EvalStruct->IsChildOf(FSequencerEvaluateBase::StaticStruct())) {
        static TSet<FString> WarnedStructs;
        if (!WarnedStructs.Contains(StructPath)) {
            WarnedStructs.Add(StructPath);
            UE_LOG(LogTemp, Warning,
                TEXT("[SequencerTrackBase] No evaluation template struct '%s' for section '%s' - this custom track will not evaluate."),
                *StructPath, *SectionClass->GetName());
        }
        return FMovieSceneEvalTemplatePtr();
    }

    UScriptStruct::ICppStructOps* StructOps = EvalStruct->GetCppStructOps();
    if (!StructOps) {
        return FMovieSceneEvalTemplatePtr();
    }

    // Reserve inline storage and construct the derived template in place. This mirrors
    // FMovieSceneEvalTemplatePtr deserialization (SerializeInlineValue in MovieSceneEvalTemplateSerializer.h).
    FMovieSceneEvalTemplatePtr Template;
    void* Allocation = Template.Reserve(StructOps->GetSize(), StructOps->GetAlignment());
    if (!Allocation) {
        return FMovieSceneEvalTemplatePtr();
    }

    EvalStruct->InitializeStruct(Allocation);
    static_cast<FSequencerEvaluateBase*>(Allocation)->SetSourceSection(&InSection);
    return Template;
}
