#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetCaptureType.h"
#include "GameWidgetCharacterSceneCaptureTypeParameter.h"
#include "GameWidgetParameterBase.h"
#include "GameWidgetCharacterSceneCaptureParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetCharacterSceneCaptureParameter : public UGameWidgetParameterBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetCaptureType, FGameWidgetCharacterSceneCaptureTypeParameter> ParameterMap;
    
    UGameWidgetCharacterSceneCaptureParameter();

};

