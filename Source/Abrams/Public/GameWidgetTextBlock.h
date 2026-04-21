#pragma once
#include "CoreMinimal.h"
#include "WidgetLocalization.h"
#include "WidgetTextBlock.h"
#include "Framework/Text/TextLayout.h"
#include "EGameWidgetFontLanguageType.h"
#include "EGameWidgetFontStyleType.h"
#include "EGameWidgetFontUseCaseType.h"
#include "GameWidgetFontSettingsLanguageType.h"
#include "GameWidgetTextSettingInterface.h"
#include "GameWidgetTextBlock.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetTextBlock : public UWidgetTextBlock, public IWidgetLocalization, public IGameWidgetTextSettingInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TextId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoLineBreak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTextScroll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETextJustify::Type> NotScrollingJustification;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceOneLine;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameWidgetFontStyleType FontStyleType;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameWidgetFontLanguageType FixedFontType;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameWidgetFontUseCaseType UseCaseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetFontSettingsLanguageType UniqueFontSettings;
    
public:
    UGameWidgetTextBlock();


    // Fix for true pure virtual functions not being implemented
};

