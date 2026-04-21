#pragma once
#include "CoreMinimal.h"
#include "GameConfigItemScrollWidget.h"
#include "GameConfigKeyboardConfigWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameConfigKeyboardConfigWidget : public UGameConfigItemScrollWidget {
    GENERATED_BODY()
public:
    UGameConfigKeyboardConfigWidget();

};

