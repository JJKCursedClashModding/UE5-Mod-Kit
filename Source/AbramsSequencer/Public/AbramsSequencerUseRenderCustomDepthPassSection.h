#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerUseRenderCustomDepthPassSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerUseRenderCustomDepthPassSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel bIsUse;
    
    UAbramsSequencerUseRenderCustomDepthPassSection();

};

