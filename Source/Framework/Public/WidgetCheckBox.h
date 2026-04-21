#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "InputWidgetBase.h"
#include "WidgetEnterable.h"
#include "WidgetCheckBox.generated.h"

class UImage;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UWidgetCheckBox : public UInputWidgetBase, public IWidgetEnterable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCheckBoxStyle CheckBoxStyle;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* CheckBoxImage;
    
public:
    UWidgetCheckBox();


    // Fix for true pure virtual functions not being implemented
};

