#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerSubSequenceConditionType.h"
#include "SequencerSectionInterface.h"
#include "Sections/MovieSceneSubSection.h"
#include "AbramsSequencerSubSequenceWithConditionSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSubSequenceWithConditionSection : public UMovieSceneSubSection, public ISequencerSectionInterface {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerSubSequenceConditionType ConditionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 platform;
    
    UAbramsSequencerSubSequenceWithConditionSection(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());


    // Fix for true pure virtual functions not being implemented
};

