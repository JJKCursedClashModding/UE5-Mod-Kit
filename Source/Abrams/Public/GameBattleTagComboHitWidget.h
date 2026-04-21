#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleTagComboHitWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleTagComboHitWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
    UGameBattleTagComboHitWidget();


    // Fix for true pure virtual functions not being implemented
};

