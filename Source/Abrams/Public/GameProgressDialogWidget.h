#pragma once
#include "CoreMinimal.h"
#include "GamePopupDialogWidgetBase.h"
#include "GameProgressDialogWidget.generated.h"

class UGameWidgetButton;
class UGameWidgetProgressBar;
class UGameWidgetTextBlock;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameProgressDialogWidget : public UGamePopupDialogWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* CancelButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetProgressBar* TimeProgressBar;
    
public:
    UGameProgressDialogWidget();

};

