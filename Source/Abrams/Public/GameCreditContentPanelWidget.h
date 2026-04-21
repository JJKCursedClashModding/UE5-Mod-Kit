#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameCreditContentPanelWidget.generated.h"

class UCanvasPanel;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCreditContentPanelWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* TargetPanel;
    
public:
    UGameCreditContentPanelWidget();

};

