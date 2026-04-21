#pragma once
#include "CoreMinimal.h"
#include "GameWidgetTextOptionBox.h"
#include "GameWidgetLobbyTextOptionBox.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetLobbyTextOptionBox : public UGameWidgetTextOptionBox {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* HeaderText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HeaderTextId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseHeaderText;
    
public:
    UGameWidgetLobbyTextOptionBox();

};

