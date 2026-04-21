#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameVsEnemyRecoveryInputAnimationWidget.generated.h"

class UGameCommonListItemWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyRecoveryInputAnimationWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonListItemWidget* CommonList;
    
public:
    UGameVsEnemyRecoveryInputAnimationWidget();

};

