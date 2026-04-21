#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetFontStyleType.h"
#include "GameWidgetFontSettings.generated.h"

class UFont;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetFontSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameWidgetFontStyleType FontStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FontSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LetterSpacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LineHeightPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFont* ForceOverrideFont;
    
    FGameWidgetFontSettings();
};

