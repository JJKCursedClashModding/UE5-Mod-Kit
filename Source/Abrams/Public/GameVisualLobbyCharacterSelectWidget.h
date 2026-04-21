#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyCharacterSelectWidget.generated.h"

class UGameVisualLobbyCharacterSelectTopWidget;
class UGameVisualLobbyCharacterSelectVariationWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyCharacterSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyCharacterSelectTopWidget* TopWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVisualLobbyCharacterSelectVariationWidget* VariationWidget;
    
public:
    UGameVisualLobbyCharacterSelectWidget();

};

