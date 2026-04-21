#pragma once
#include "CoreMinimal.h"
#include "GameBattleTransitionWidgetBase.h"
#include "GameBattleStartNormalWidget.generated.h"

class UOverlay;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleStartNormalWidget : public UGameBattleTransitionWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Subtext_Group_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Subtext_Group_2;
    
public:
    UGameBattleStartNormalWidget();

};

