#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerUMGMaterialTextureParameterName.h"
#include "Channels/MovieSceneObjectPathChannel.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerSetUMGMaterialTextureParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetUMGMaterialTextureParameterSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneObjectPathChannel Texture;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerUMGMaterialTextureParameterName ParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DynamicParameterName;
    
    UAbramsSequencerSetUMGMaterialTextureParameterSection();

};

