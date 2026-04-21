#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterCaptureType.h"
#include "GameWidgetCaptureRenderTargetParameter.h"
#include "GameWidgetParameterBase.h"
#include "GameWidgetSceneCaptureParameter.generated.h"

class UGameWidgetCharacterSceneCaptureParameter;
class UGameWidgetSceneCaptureTypeParameter;

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetSceneCaptureParameter : public UGameWidgetParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameCharacterCaptureType, UGameWidgetSceneCaptureTypeParameter*> CaptureParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UGameWidgetCharacterSceneCaptureParameter*> CharacterParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameWidgetCaptureRenderTargetParameter> CaptureRenderTargetArray;
    
public:
    UGameWidgetSceneCaptureParameter();

};

