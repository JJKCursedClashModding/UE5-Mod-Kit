#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "EGameWidgetInputGuideType.h"
#include "GameWidgetFallbackInputGuideOverrideBrushInfo.h"
#include "GameWidgetFallbackInputGuideParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetFallbackInputGuideParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush InputGuideBrush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetInputGuideType, FGameWidgetFallbackInputGuideOverrideBrushInfo> OverrideBrushMap;
    
    FGameWidgetFallbackInputGuideParameter();
};

