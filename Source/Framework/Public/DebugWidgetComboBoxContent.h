#pragma once
#include "CoreMinimal.h"
#include "WidgetComboBoxContent.h"
#include "DebugWidgetComboBoxContent.generated.h"

class UOverlay;
class UWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetComboBoxContent : public UWidgetComboBoxContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetTextBlock* ButtonText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Overlay;
    
public:
    UDebugWidgetComboBoxContent();

};

