#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleCharacterMarkerCursorWidget.generated.h"

class UGameWidgetNiagaraEffect;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleCharacterMarkerCursorWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetNiagaraEffect* TagComboChance;
    
public:
    UGameBattleCharacterMarkerCursorWidget();

};

