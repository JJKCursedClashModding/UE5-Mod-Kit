#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleSituationOverviewArcadeMissionWidget.generated.h"

class UGameBattleSituationOverviewArcadeCharacterIconWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSituationOverviewArcadeMissionWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleSituationOverviewArcadeCharacterIconWidget* CharacterIconLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleSituationOverviewArcadeCharacterIconWidget* CharacterIconRight;
    
public:
    UGameBattleSituationOverviewArcadeMissionWidget();

};

