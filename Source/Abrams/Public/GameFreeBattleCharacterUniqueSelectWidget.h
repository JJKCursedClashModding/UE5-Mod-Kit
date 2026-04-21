#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameFreeBattleCharacterUniqueSelectWidget.generated.h"

class UGameFreeBattleRuleListItemWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameFreeBattleCharacterUniqueSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* TensionGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* PassionGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* ThroatGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* OvertimeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* StrongestAwakeningListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleRuleListItemWidget* BloodManipulationGaugeListItem;
    
public:
    UGameFreeBattleCharacterUniqueSelectWidget();

};

