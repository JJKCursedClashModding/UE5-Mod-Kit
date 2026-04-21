#pragma once
#include "CoreMinimal.h"
#include "GameBattleDashGaugeThreshold.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleDashGaugeWidget.generated.h"

class UGameWidgetImage;
class UProgressBar;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleDashGaugeWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameBattleDashGaugeThreshold> DashGaugeThresholdArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProgressBar* DashGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* DashGauge_Icon;
    
public:
    UGameBattleDashGaugeWidget();


    // Fix for true pure virtual functions not being implemented
};

