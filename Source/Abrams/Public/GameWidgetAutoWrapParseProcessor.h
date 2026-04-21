#pragma once
#include "CoreMinimal.h"
#include "GameWidgetMarkupParseProcessor.h"
#include "GameWidgetAutoWrapParseProcessor.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetAutoWrapParseProcessor : public UGameWidgetMarkupParseProcessor {
    GENERATED_BODY()
public:
    UGameWidgetAutoWrapParseProcessor();

};

