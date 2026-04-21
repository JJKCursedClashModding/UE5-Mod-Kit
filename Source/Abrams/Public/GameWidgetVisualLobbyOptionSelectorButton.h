#pragma once
#include "CoreMinimal.h"
#include "GameWidgetOptionSelectorButton.h"
#include "GameWidgetVisualLobbyOptionSelectorButton.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetVisualLobbyOptionSelectorButton : public UGameWidgetOptionSelectorButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* FocusedImage;
    
public:
    UGameWidgetVisualLobbyOptionSelectorButton();

};

