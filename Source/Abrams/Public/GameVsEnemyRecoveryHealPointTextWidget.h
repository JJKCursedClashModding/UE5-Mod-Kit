#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameVsEnemyRecoveryHealPointTextWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyRecoveryHealPointTextWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CharacterIndexText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* HealPointText;
    
public:
    UGameVsEnemyRecoveryHealPointTextWidget();

};

