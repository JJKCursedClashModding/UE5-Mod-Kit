#pragma once
#include "CoreMinimal.h"
#include "GameWidgetCameraCaptureParameter.h"
#include "GameWidgetLightCaptureParameter.h"
#include "GameWidgetParameterBase.h"
#include "GameWidgetSceneCaptureTypeParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetSceneCaptureTypeParameter : public UGameWidgetParameterBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetCameraCaptureParameter CameraParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetLightCaptureParameter LightParameter;
    
    UGameWidgetSceneCaptureTypeParameter();

};

