#pragma once
#include "CoreMinimal.h"
#include "WidgetButton.h"
#include "DebugWidgetButton.generated.h"

class UOverlay;

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetButton : public UWidgetButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Overlay;
    
public:
    UDebugWidgetButton();

};

