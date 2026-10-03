#pragma once
#include "CoreMinimal.h"
#include "GameWidgetVsEnemyLockButton.h"
#include "GameWidgetVsEnemyBattleModeButton.generated.h"

class UGameVsEnemyBattleModeAnimationWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetVsEnemyBattleModeButton : public UGameWidgetVsEnemyLockButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyBattleModeAnimationWidget* AnimationWidget;
    
public:
    UGameWidgetVsEnemyBattleModeButton();

};

