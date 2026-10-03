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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* TensionGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* PassionGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* ThroatGaugeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* OvertimeListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* StrongestAwakeningListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleListItemWidget* BloodManipulationGaugeListItem;
    
public:
    UGameFreeBattleCharacterUniqueSelectWidget();

};

