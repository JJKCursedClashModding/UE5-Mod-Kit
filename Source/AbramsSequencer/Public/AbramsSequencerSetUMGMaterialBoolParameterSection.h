#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerUMGMaterialBoolParameterName.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerSetUMGMaterialBoolParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetUMGMaterialBoolParameterSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel Value;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerUMGMaterialBoolParameterName ParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DynamicParameterName;
    
    UAbramsSequencerSetUMGMaterialBoolParameterSection();

};

