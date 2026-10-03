#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MovieSceneTrack.h"
#include "Compilation/IMovieSceneTrackTemplateProducer.h"
#include "SequencerTrackInterface.h"
#include "SequencerTrackBase.generated.h"

class UMovieSceneSection;

// UE 5.1 still evaluates legacy serialized templates for tracks that implement
// IMovieSceneTrackTemplateProducer (see MovieSceneCompiledDataManager.cpp CompileTrack).
// The game's original modules implemented this for every custom track; the project
// reconstruction must do the same, otherwise re-cooked (editor-saved) sequences lose
// their custom evaluation templates at cook time.
// See Saved/uncooker_investigation_report.md (findings F2/F3).
UCLASS(Abstract, Blueprintable)
class FRAMEWORK_API USequencerTrackBase : public UMovieSceneTrack, public ISequencerTrackInterface, public IMovieSceneTrackTemplateProducer {
    GENERATED_BODY()
public:
    USequencerTrackBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    // UMovieSceneTrack overrides
    virtual const TArray<UMovieSceneSection*>& GetAllSections() const override { return Sections; }
    virtual bool HasSection(const UMovieSceneSection& Section) const override { return Sections.Contains(&Section); }
    virtual bool IsEmpty() const override { return Sections.IsEmpty(); }
    virtual void RemoveAllAnimationData() override { Sections.Empty(); }
    virtual void AddSection(UMovieSceneSection& Section) override { Sections.Add(&Section); }
    virtual void RemoveSection(UMovieSceneSection& Section) override { Sections.Remove(&Section); }
    virtual void RemoveSectionAt(int32 SectionIndex) override { Sections.RemoveAt(SectionIndex); }

protected:
    // IMovieSceneTrackTemplateProducer: produce the F<...>Evaluate struct matching each section class.
    virtual FMovieSceneEvalTemplatePtr CreateTemplateForSection(const UMovieSceneSection& InSection) const override;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMovieSceneSection*> Sections;
};
