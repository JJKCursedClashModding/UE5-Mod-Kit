#pragma once
#include "CoreMinimal.h"
#include "GameWidgetEditableText.h"
#include "GameWidgetLobbyEditableText.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetLobbyEditableText : public UGameWidgetEditableText {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* HeaderText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HeaderTextId;
    
public:
    UGameWidgetLobbyEditableText();

};

