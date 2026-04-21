#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerMaterialVectorParameterName.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionEffectMaterialParamBase.h"
#include "AbramsSequencerSetEffectMaterialVectorParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetEffectMaterialVectorParameterSection : public UAbramsSequencerSectionEffectMaterialParamBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel ValueX;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel ValueY;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel ValueZ;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerMaterialVectorParameterName ParameterName;
    
    UAbramsSequencerSetEffectMaterialVectorParameterSection();

};

