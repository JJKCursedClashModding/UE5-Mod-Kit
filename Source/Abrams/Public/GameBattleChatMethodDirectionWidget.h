#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleChatMethodDirectionWidget.generated.h"

class UGameWidgetExchangeImage;
class UGameWidgetInputImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleChatMethodDirectionWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* DirectionIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetExchangeImage* ChatIcon;
    
public:
    UGameBattleChatMethodDirectionWidget();

};

