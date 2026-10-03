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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVsEnemyLockButton* RushButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVsEnemyLockButton* SurvivalButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVsEnemyLockButton* CharacterSettingsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVsEnemyLockButton* RankingButton;
    
public:
    UGameVsEnemyBattleModeWidget();

};

