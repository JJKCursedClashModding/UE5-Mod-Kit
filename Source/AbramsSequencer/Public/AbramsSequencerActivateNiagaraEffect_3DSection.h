#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionBindingEffectBase.h"
#include "AbramsSequencerActivateNiagaraEffect_3DSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerActivateNiagaraEffect_3DSection : public UAbramsSequencerSectionBindingEffectBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel bActivate;
    
    UAbramsSequencerActivateNiagaraEffect_3DSection();

};

