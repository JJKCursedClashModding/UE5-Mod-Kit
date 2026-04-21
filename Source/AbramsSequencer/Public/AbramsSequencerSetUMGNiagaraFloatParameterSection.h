#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionUMGBindingNiagaraComponentBase.h"
#include "AbramsSequencerSetUMGNiagaraFloatParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetUMGNiagaraFloatParameterSection : public UAbramsSequencerSectionUMGBindingNiagaraComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParameterName;
    
    UAbramsSequencerSetUMGNiagaraFloatParameterSection();

};

