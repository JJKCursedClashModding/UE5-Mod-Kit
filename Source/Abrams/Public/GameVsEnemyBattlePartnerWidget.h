#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVsEnemyBattlePartnerWidget.generated.h"

class UGameWidgetVsEnemyLockButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyBattlePartnerWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyLockButton* OfflineButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyLockButton* OnlineButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyLockButton* CharacterSettingsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyLockButton* RankingButton;
    
public:
    UGameVsEnemyBattlePartnerWidget();

};

