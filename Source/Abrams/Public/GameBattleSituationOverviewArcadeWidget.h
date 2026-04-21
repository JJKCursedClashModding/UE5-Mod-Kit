#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleSituationOverviewArcadeWidget.generated.h"

class UGameBattleSituationOverviewArcadeMissionWidget;
class UGameBattleSituationOverviewArcadeProgressBarWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSituationOverviewArcadeWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeMissionWidget* Mission_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeMissionWidget* Mission_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeMissionWidget* Mission_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeMissionWidget* Mission_4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeMissionWidget* Mission_5;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeProgressBarWidget* ProgressBar_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeProgressBarWidget* ProgressBar_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeProgressBarWidget* ProgressBar_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeProgressBarWidget* ProgressBar_4;
    
public:
    UGameBattleSituationOverviewArcadeWidget();

};

