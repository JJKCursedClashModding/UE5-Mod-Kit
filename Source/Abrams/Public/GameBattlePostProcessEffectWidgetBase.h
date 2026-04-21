#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattlePostProcessEffectWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattlePostProcessEffectWidgetBase : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
    UGameBattlePostProcessEffectWidgetBase();


    // Fix for true pure virtual functions not being implemented
};

