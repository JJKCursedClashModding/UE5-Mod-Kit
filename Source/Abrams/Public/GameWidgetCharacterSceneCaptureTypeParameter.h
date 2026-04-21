#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetCharacterCostumeType.h"
#include "GameWidgetCharacterCaptureCommonParameter.h"
#include "GameWidgetCharacterCaptureVariationParameter.h"
#include "GameWidgetCharacterSceneCaptureTypeParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetCharacterSceneCaptureTypeParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetCharacterCaptureCommonParameter CommonParameter;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetCharacterCostumeType, FGameWidgetCharacterCaptureVariationParameter> VariationParameterMap;
    
    FGameWidgetCharacterSceneCaptureTypeParameter();
};

