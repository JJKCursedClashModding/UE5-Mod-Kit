#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "GameWidgetFallbackInputGuideOverrideBrushInfo.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetFallbackInputGuideOverrideBrushInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush Brush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush SmallBrush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush TinyBrush;
    
    FGameWidgetFallbackInputGuideOverrideBrushInfo();
};

