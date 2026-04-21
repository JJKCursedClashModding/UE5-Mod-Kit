#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GameRankingFilterToggleButtonWidget.generated.h"

class UCanvasPanel;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRankingFilterToggleButtonWidget : public UGameWidgetButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* CheckIconPanel;
    
public:
    UGameRankingFilterToggleButtonWidget();

};

