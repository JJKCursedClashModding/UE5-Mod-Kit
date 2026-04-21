#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVsEnemyBattleModeWidget.generated.h"

class UGameWidgetVsEnemyLockButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyBattleModeWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyLockButton* RushButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyLockButton* SurvivalButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyLockButton* CharacterSettingsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyLockButton* RankingButton;
    
public:
    UGameVsEnemyBattleModeWidget();

};

