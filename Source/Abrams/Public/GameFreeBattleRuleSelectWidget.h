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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* StageListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* TimeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* BGMListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* FixedCursedEnergyListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* ConsumeCursedEnergyListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* ConsumeDashGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* ConsumeCostGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* DisplayDamageListItem;
    
public:
    UGameFreeBattleRuleSelectWidget();

};

