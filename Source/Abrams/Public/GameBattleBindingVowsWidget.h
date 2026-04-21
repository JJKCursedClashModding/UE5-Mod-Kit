#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleBindingVowsWidget.generated.h"

class UGameBindingVowsWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleBindingVowsWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBindingVowsWidget* BindingVowsIcon;
    
public:
    UGameBattleBindingVowsWidget();

};

