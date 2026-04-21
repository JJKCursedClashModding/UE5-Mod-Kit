#pragma once
#include "CoreMinimal.h"
#include "WidgetLocalization.h"
#include "WidgetRichTextBlock.h"
#include "WidgetTransitionable.h"
#include "Framework/Text/TextLayout.h"
#include "EGameWidgetFontLanguageType.h"
#include "EGameWidgetFontStyleType.h"
#include "EGameWidgetFontUseCaseType.h"
#include "GameWidgetFontSettingsLanguageType.h"
#include "GameWidgetTextSettingInterface.h"
#include "Templates/SubclassOf.h"
#include "GameWidgetRichTextBlock.generated.h"

class URichTextBlockDecorator;

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetRichTextBlock : public UWidgetRichTextBlock, public IWidgetTransitionable, public IWidgetLocalization, public IGameWidgetTextSettingInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TextId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoLineBreak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoLineBreakUseDesiredMaxSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTextScroll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETextJustify::Type> NotScrollingJustification;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceOneLine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultStyleName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URichTextBlockDecorator> Decorator;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameWidgetFontStyleType FontStyleType;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameWidgetFontLanguageType FixedFontType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDecoratorFontStyle;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameWidgetFontUseCaseType UseCaseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetFontSettingsLanguageType UniqueFontSettings;
    
public:
    UGameWidgetRichTextBlock();


    // Fix for true pure virtual functions not being implemented
};

