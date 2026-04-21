#pragma once
#include "CoreMinimal.h"
#include "GameConfigCategoryWidgetBase.h"
#include "GameConfigItemScrollWidget.generated.h"

class UGameConfigItemScrollListWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameConfigItemScrollWidget : public UGameConfigCategoryWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameConfigItemScrollListWidget* ScrollListView;
    
public:
    UGameConfigItemScrollWidget();

};

