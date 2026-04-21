#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetFontLanguageType.h"
#include "GameWidgetFontSettings.h"
#include "GameWidgetFontSettingsLanguageType.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetFontSettingsLanguageType {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetFontLanguageType, FGameWidgetFontSettings> SettingsMap;
    
public:
    FGameWidgetFontSettingsLanguageType();
};

