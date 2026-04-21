#pragma once
#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "GameWidgetRichTextBlockDecoratorBase.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMS_API UGameWidgetRichTextBlockDecoratorBase : public URichTextBlockDecorator {
    GENERATED_BODY()
public:
    UGameWidgetRichTextBlockDecoratorBase();

};

