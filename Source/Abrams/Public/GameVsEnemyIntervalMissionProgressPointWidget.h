#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameVsEnemyIntervalMissionProgressPointWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyIntervalMissionProgressPointWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ClearedImage;
    
public:
    UGameVsEnemyIntervalMissionProgressPointWidget();

};

