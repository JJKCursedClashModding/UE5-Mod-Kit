#pragma once
#include "CoreMinimal.h"
#include "Components/ProgressBar.h"
#include "DebugWidgetProgressBar.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API UDebugWidgetProgressBar : public UProgressBar {
    GENERATED_BODY()
public:
    UDebugWidgetProgressBar();

};

