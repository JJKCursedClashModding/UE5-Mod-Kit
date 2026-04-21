#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetCaptureBackgroundColor.generated.h"

UENUM()
enum class EGameWidgetCaptureBackgroundColor : int32 {
    None,
    Red,
    Green,
    Blue,
    Cyan,
    Magenta,
    Yellow,
    Details,
    Invalid,
};

