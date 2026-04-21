#pragma once
#include "CoreMinimal.h"
#include "WidgetListViewBase.h"
#include "WidgetListView.generated.h"

class UListViewWrapper;

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UWidgetListView : public UWidgetListViewBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UListViewWrapper* ListView;
    
public:
    UWidgetListView();

};

