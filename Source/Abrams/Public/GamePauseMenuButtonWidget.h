#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GamePauseMenuButtonWidget.generated.h"

class UCanvasPanel;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGamePauseMenuButtonWidget : public UGameWidgetButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* BG_Cursor;
    
public:
    UGamePauseMenuButtonWidget();

};

