#pragma once
#include "CoreMinimal.h"
#include "EInputDeviceIndex.generated.h"

UENUM(BlueprintType)
enum class EInputDeviceIndex : uint8 {
    Keyboard,
    Mouse = Keyboard,
    Pad1 = Keyboard,
    Pad2,
    Pad3,
    Pad4,
};

