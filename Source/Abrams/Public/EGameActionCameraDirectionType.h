#pragma once
#include "CoreMinimal.h"
#include "EGameActionCameraDirectionType.generated.h"

UENUM(BlueprintType)
enum class EGameActionCameraDirectionType : uint8 {
    OwnerToTarget,
    OwnerToTargetYaw,
    OwnerForward,
    OwnerForwardYaw,
    TargetForward,
    TargetForwardYaw,
    CameraToOwner,
    CameraToOwnerYaw,
    CameraToTarget,
    CameraToTargetYaw,
    WorldX,
    TargetToOwner,
    TargetToOwnerYaw,
    Invalid = 255,
};

