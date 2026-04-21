#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerMaterialScalarParameterName.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionEffectMaterialParamBase.h"
#include "AbramsSequencerSetEffectMaterialScalarParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetEffectMaterialScalarParameterSection : public UAbramsSequencerSectionEffectMaterialParamBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel Value;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerMaterialScalarParameterName ParameterName;
    
    UAbramsSequencerSetEffectMaterialScalarParameterSection();

};

