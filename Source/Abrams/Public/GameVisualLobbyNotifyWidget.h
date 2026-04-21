#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyNotifyWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyNotifyWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* NotifyText;
    
public:
    UGameVisualLobbyNotifyWidget();

};

