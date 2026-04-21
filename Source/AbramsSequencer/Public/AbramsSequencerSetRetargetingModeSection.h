#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionAnimationBase.h"
#include "AbramsSequencerSetRetargetingModeSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetRetargetingModeSection : public UAbramsSequencerSectionAnimationBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel bEnable;
    
    UAbramsSequencerSetRetargetingModeSection();

};

