#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleForceGaugeWidget.generated.h"

class UHorizontalBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleForceGaugeWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IconDisappearanceDelayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHorizontalBox* IconHorizontalBox;
    
public:
    UGameBattleForceGaugeWidget();


    // Fix for true pure virtual functions not being implemented
};

