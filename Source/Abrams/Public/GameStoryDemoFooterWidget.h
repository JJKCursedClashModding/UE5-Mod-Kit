#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryDemoFooterWidget.generated.h"

class UBorder;
class UGameStoryDemoFooterButtonWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryDemoFooterWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryDemoFooterButtonWidget* SkipButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryDemoFooterButtonWidget* AutoButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryDemoFooterButtonWidget* NextButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* Border;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* Border_1;
    
public:
    UGameStoryDemoFooterWidget();

};

