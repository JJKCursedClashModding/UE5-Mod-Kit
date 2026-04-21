#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameCharacterSelectArcadeRewardInfoWidget.generated.h"

class UGameWidgetTextBlock;
class UOverlay;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCharacterSelectArcadeRewardInfoWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* RootOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* RewardItemName;
    
public:
    UGameCharacterSelectArcadeRewardInfoWidget();

};

