#pragma once
#include "CoreMinimal.h"
#include "WidgetOptionBoxBase.h"
#include "WidgetTextBlockAutoSizeParameter.h"
#include "WidgetTextOptionBox.generated.h"

class UWidgetTextBlock;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UWidgetTextOptionBox : public UWidgetOptionBoxBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetTextBlock* TextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWidgetTextBlockAutoSizeParameter AutoSizeParameter;
    
public:
    UWidgetTextOptionBox();

};

