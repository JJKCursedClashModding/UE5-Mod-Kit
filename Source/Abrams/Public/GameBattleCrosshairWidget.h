#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleCrosshairWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleCrosshairWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
    UGameBattleCrosshairWidget();


    // Fix for true pure virtual functions not being implemented
};

