#pragma once
#include "CoreMinimal.h"
#include "WidgetButton.h"
#include "WidgetListItem.h"
#include "WidgetComboBoxContent.generated.h"

class UImage;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UWidgetComboBoxContent : public UWidgetButton, public IWidgetListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* BackgroundImage;
    
public:
    UWidgetComboBoxContent();


    // Fix for true pure virtual functions not being implemented
};

