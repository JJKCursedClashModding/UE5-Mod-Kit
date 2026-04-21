#pragma once
#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "WidgetActivatable.h"
#include "WidgetTextBlockAutoSizeParameter.h"
#include "WidgetWorldTickable.h"
#include "WidgetTextBlock.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API UWidgetTextBlock : public UTextBlock, public IWidgetWorldTickable, public IWidgetActivatable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWidgetTextBlockAutoSizeParameter AutoSizeParameter;
    
public:
    UWidgetTextBlock();


    // Fix for true pure virtual functions not being implemented
};

