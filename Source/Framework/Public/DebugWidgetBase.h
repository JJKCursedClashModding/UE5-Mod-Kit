#pragma once
#include "CoreMinimal.h"
#include "WindowBase.h"
#include "DebugWidgetBase.generated.h"

class UCanvasPanel;
class UDebugWidgetExplanation;
class UDebugWidgetTextBlock;
class UWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetBase : public UWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* CanvasRootWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetExplanation* Explanation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCanvasPanel*> PageWidgetArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDebugWidgetTextBlock*> TextBlockArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<UWidget*, UDebugWidgetTextBlock*> WidgetTextMap;
    
public:
    UDebugWidgetBase();

};

