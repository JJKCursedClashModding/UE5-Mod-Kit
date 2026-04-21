#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerUMGMaterialTextureParameterName.h"
#include "Channels/MovieSceneStringChannel.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerSetUMGMaterialTextureParameterFromNameSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetUMGMaterialTextureParameterFromNameSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneStringChannel Filename;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerUMGMaterialTextureParameterName ParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DynamicParameterName;
    
    UAbramsSequencerSetUMGMaterialTextureParameterFromNameSection();

};

