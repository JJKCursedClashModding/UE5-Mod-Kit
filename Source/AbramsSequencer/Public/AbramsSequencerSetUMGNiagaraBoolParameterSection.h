#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionUMGBindingNiagaraComponentBase.h"
#include "AbramsSequencerSetUMGNiagaraBoolParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetUMGNiagaraBoolParameterSection : public UAbramsSequencerSectionUMGBindingNiagaraComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParameterName;
    
    UAbramsSequencerSetUMGNiagaraBoolParameterSection();

};

