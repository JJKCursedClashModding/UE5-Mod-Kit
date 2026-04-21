#pragma once
#include "CoreMinimal.h"
#include "WidgetHoverable.h"
#include "GameWidgetBase.h"
#include "GameFreeBattleRuleListItemWidget.generated.h"

class UGameCommonListItemWidget;
class UGameWidgetFreeBattleTextOptionBox;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameFreeBattleRuleListItemWidget : public UGameWidgetBase, public IWidgetHoverable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* HeaderText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HeaderTextId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CharacterText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterTextId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetFreeBattleTextOptionBox* OptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonListItemWidget* WBP_CommonListItem_01;
    
public:
    UGameFreeBattleRuleListItemWidget();


    // Fix for true pure virtual functions not being implemented
};

