#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerMaterialBoolParameterName.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionEffectMaterialParamBase.h"
#include "AbramsSequencerSetEffectMaterialBoolParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetEffectMaterialBoolParameterSection : public UAbramsSequencerSectionEffectMaterialParamBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel bValue;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerMaterialBoolParameterName ParameterName;
    
    UAbramsSequencerSetEffectMaterialBoolParameterSection();

};

