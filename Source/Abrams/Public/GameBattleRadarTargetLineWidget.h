#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleRadarTargetLineWidget.generated.h"

class UCanvasPanel;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleRadarTargetLineWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* TargetLineCanvas;
    
public:
    UGameBattleRadarTargetLineWidget();

};

