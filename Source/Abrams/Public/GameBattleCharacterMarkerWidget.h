#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleCharacterMarkerWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleCharacterMarkerWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
    UGameBattleCharacterMarkerWidget();


    // Fix for true pure virtual functions not being implemented
};

