#pragma once
#include "CoreMinimal.h"
#include "EApplicationPlatform.generated.h"

UENUM(BlueprintType)
enum class EApplicationPlatform : uint8 {
    Windows,
    PS4,
    PS5,
    Switch,
    XB1,
    XSX,
    WinGDK,
    Invalid = 255,
};

