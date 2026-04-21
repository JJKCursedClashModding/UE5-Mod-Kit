#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UWidgetBase : public UUserWidget {
    GENERATED_BODY()
public:
    UWidgetBase();

};

