#pragma once
#include "CoreMinimal.h"
#include "WidgetComboBox.h"
#include "DebugWidgetComboBox.generated.h"

class UDebugWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetComboBox : public UWidgetComboBox {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetTextBlock* ButtonText;
    
public:
    UDebugWidgetComboBox();

};

