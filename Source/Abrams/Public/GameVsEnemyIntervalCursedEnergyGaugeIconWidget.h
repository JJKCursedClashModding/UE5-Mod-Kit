#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameVsEnemyIntervalCursedEnergyGaugeIconWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyIntervalCursedEnergyGaugeIconWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* IconImage;
    
public:
    UGameVsEnemyIntervalCursedEnergyGaugeIconWidget();

};

