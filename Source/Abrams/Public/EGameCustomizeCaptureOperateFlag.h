#pragma once
#include "CoreMinimal.h"
#include "EGameCustomizeCaptureOperateFlag.generated.h"

UENUM(BlueprintType)
enum class EGameCustomizeCaptureOperateFlag : uint8 {
    None,
    ChangeDistance_Increase,
    ChangeDistance_Decrease,
    ChangeRotationYaw_Increase = 4,
    ChangeRotationYaw_Decrease = 8,
};

