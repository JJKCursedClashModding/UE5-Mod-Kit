#pragma once
#include "CoreMinimal.h"
#include "GameCollectionModeWidgetBase.h"
#include "GameCollectionPlayRecordWidget.generated.h"

class UGameCollectionPlayRecordListWidget;
class UGameCollectionPlayRecordSimpleWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionPlayRecordWidget : public UGameCollectionModeWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionPlayRecordSimpleWidget* SimpleRecordWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionPlayRecordListWidget* AllRecordListWidget;
    
public:
    UGameCollectionPlayRecordWidget();

};

