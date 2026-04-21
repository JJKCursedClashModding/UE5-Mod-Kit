#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GameWidgetVisualLobbyRoomInfoPlayerItemButton.generated.h"

class UGameWidgetInputGuideText;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetVisualLobbyRoomInfoPlayerItemButton : public UGameWidgetButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InputGuideTextId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputGuideText* InputGuideText;
    
public:
    UGameWidgetVisualLobbyRoomInfoPlayerItemButton();

};

