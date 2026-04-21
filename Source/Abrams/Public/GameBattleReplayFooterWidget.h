#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameWidgetResolution.h"
#include "GameBattleReplayFooterWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleReplayFooterWidget : public UGameWidgetBase, public IGameBattleWidgetContent, public IGameWidgetResolution {
    GENERATED_BODY()
public:
    UGameBattleReplayFooterWidget();


    // Fix for true pure virtual functions not being implemented
};

