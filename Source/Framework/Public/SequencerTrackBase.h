#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MovieSceneTrack.h"
#include "SequencerTrackInterface.h"
#include "SequencerTrackBase.generated.h"

class UMovieSceneSection;

// UMovieSceneNameableTrack was removed in UE 5.1 — replaced by UMovieSceneTrack.
// IMovieSceneTrackTemplateProducer was also removed (template evaluation replaced by entity system).
UCLASS(Abstract, Blueprintable)
class FRAMEWORK_API USequencerTrackBase : public UMovieSceneTrack, public ISequencerTrackInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMovieSceneSection*> Sections;
    
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
};
