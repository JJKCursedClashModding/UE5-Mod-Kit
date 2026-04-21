#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetFontLanguageType.h"
#include "EGameWidgetFontUseCaseType.h"
#include "GameWidgetFontLanguageParameter.h"
#include "GameWidgetFontSettingsLanguageType.h"
#include "GameWidgetParameterBase.h"
#include "GameWidgetFontParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetFontParameter : public UGameWidgetParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetFontLanguageType, FGameWidgetFontLanguageParameter> FontParameterMap;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetFontUseCaseType, FGameWidgetFontSettingsLanguageType> FontSettingsMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetFontSettingsLanguageType SystemDialogSupplementFontSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetFontSettingsLanguageType MainMenuSubTextColorChangeFontSettings;
    
public:
    UGameWidgetFontParameter();

};

