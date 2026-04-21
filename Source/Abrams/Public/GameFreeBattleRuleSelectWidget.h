#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameFreeBattleRuleSelectWidget.generated.h"

class UGameFreeBattleRuleListItemWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameFreeBattleRuleSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* StageListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* TimeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* BGMListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* FixedCursedEnergyListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* ConsumeCursedEnergyListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* ConsumeDashGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* ConsumeCostGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* DisplayDamageListItem;
    
public:
    UGameFreeBattleRuleSelectWidget();

};

