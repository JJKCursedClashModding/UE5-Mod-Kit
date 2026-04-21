#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameWidgetResolution.h"
#include "GameBattleAdaptIconListWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleAdaptIconListWidget : public UGameWidgetBase, public IGameBattleWidgetContent, public IGameWidgetResolution {
    GENERATED_BODY()
public:
    UGameBattleAdaptIconListWidget();


    // Fix for true pure virtual functions not being implemented
};

