#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleNotifyIconWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleNotifyIconWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CharacterIcon;
    
public:
    UGameBattleNotifyIconWidget();

};

