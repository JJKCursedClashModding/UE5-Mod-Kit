#pragma once
#include "CoreMinimal.h"
#include "WidgetCheckBox.h"
#include "DebugWidgetCheckBox.generated.h"

class UOverlay;

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetCheckBox : public UWidgetCheckBox {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Overlay;
    
public:
    UDebugWidgetCheckBox();

};

