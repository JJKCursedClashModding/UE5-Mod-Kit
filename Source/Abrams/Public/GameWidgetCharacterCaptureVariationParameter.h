#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetCaptureBackgroundColor.h"
#include "GameWidgetCharacterCaptureBackgroundColorDetails.h"
#include "GameWidgetCharacterCaptureVariationParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetCharacterCaptureVariationParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaterialPattern;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameWidgetCaptureBackgroundColor BackgroundColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetCharacterCaptureBackgroundColorDetails BackgroundColorDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToneCurveAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlphaExp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Mask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CutOffMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CutOffMin;
    
    FGameWidgetCharacterCaptureVariationParameter();
};

