#pragma once
#include "CoreMinimal.h"
#include "DebugWidgetBase.h"
#include "GameDebugScriptCategoryData.h"
#include "DebugScriptWidget.generated.h"

class UDebugScriptListViewWidget;
class UDebugWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UDebugScriptWidget : public UDebugWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetTextBlock* ScriptListTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugScriptListViewWidget* CategoryListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugScriptListViewWidget* ScriptListView;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameDebugScriptCategoryData> ScriptFileItemMap;
    
public:
    UDebugScriptWidget();

};

