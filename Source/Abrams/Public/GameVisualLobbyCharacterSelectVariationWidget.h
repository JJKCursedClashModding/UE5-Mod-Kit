#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameWindowBase.h"
#include "GameVisualLobbyCharacterSelectVariationWidget.generated.h"

class UGameWidgetVisualLobbyTextOptionBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyCharacterSelectVariationWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor GrayDownColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyTextOptionBox* CostumeSelectOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVisualLobbyTextOptionBox* ColorVariationSelectOptionBox;
    
public:
    UGameVisualLobbyCharacterSelectVariationWidget();

};

