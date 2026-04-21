#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterCaptureType.h"
#include "GameWidgetCaptureRenderTargetParameter.generated.h"

class UGameTextureRenderTarget2D;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetCaptureRenderTargetParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterCaptureType CaptureType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameTextureRenderTarget2D* RenderTarget;
    
    FGameWidgetCaptureRenderTargetParameter();
};

