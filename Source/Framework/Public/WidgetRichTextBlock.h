#pragma once
#include "CoreMinimal.h"
#include "Components/RichTextBlock.h"
#include "WidgetActivatable.h"
#include "WidgetWorldTickable.h"
#include "WidgetRichTextBlock.generated.h"

UCLASS(Abstract, Blueprintable)
class FRAMEWORK_API UWidgetRichTextBlock : public URichTextBlock, public IWidgetWorldTickable, public IWidgetActivatable {
    GENERATED_BODY()
public:
    UWidgetRichTextBlock();


    // Fix for true pure virtual functions not being implemented
};

