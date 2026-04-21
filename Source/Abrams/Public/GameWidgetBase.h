#pragma once
#include "CoreMinimal.h"
#include "WidgetBase.h"
#include "GameWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetBase : public UWidgetBase {
    GENERATED_BODY()
public:
    UGameWidgetBase();

};

