#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionBindingEffectBase.h"
#include "AbramsSequencerSetEffectCustomTimeDilationSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetEffectCustomTimeDilationSection : public UAbramsSequencerSectionBindingEffectBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel bActivate;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel Dilation;
    
    UAbramsSequencerSetEffectCustomTimeDilationSection();

};

