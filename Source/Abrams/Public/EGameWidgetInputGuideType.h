#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetInputGuideType.generated.h"

UENUM(BlueprintType)
enum class EGameWidgetInputGuideType : uint8 {
    Invalid,
    Keyboard,
    XInput,
    DualShock,
    DualSense,
    SwitchProController,
    JoyCon,
};

