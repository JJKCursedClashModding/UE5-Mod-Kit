#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleMissionTaskListWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleMissionTaskListWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
    UGameBattleMissionTaskListWidget();


    // Fix for true pure virtual functions not being implemented
};

