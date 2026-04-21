#pragma once
#include "CoreMinimal.h"
#include "GamePopupDialogWidgetBase.h"
#include "GameSystemDialogWidget.generated.h"

class UGameWidgetButton;
class UGameWidgetProgressBar;
class UGameWidgetRichTextBlock;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameSystemDialogWidget : public UGamePopupDialogWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* TitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* OkButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* YesButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* NOButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetProgressBar* TimeProgressBar;
    
public:
    UGameSystemDialogWidget();

};

