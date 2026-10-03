#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameCollectionPlayRecordSimpleWidget.generated.h"

class UGameCollectionPlayRecordTopWinRateWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionPlayRecordSimpleWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCollectionPlayRecordTopWinRateWidget* TopWinRatePvPWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCollectionPlayRecordTopWinRateWidget* TopWinRatePvEWidget;
    
public:
    UGameCollectionPlayRecordSimpleWidget();

};

