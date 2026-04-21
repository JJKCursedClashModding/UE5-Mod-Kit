#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerUMGMaterialVectorParameterName.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerSetUMGMaterialVectorParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetUMGMaterialVectorParameterSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel ValueR;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel ValueG;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel ValueB;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel ValueA;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerUMGMaterialVectorParameterName ParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DynamicParameterName;
    
    UAbramsSequencerSetUMGMaterialVectorParameterSection();

};

