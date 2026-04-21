#pragma once
#include "CoreMinimal.h"
#include "GamePopupDialogWidgetBase.h"
#include "GameAutoSaveDescriptionDialogWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameAutoSaveDescriptionDialogWidget : public UGamePopupDialogWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TitleText;
    
public:
    UGameAutoSaveDescriptionDialogWidget();

};

