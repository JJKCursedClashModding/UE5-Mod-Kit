#pragma once
#include "CoreMinimal.h"
#include "EInputKey.generated.h"

UENUM()
enum class EInputKey : uint32 {
    None,
    Circle,
    Cross,
    Triangle = 4,
    Square = 8,
    DPad_Left = 16,
    DPad_Right = 32,
    DPad_Up = 64,
    DPad_Down = 128,
    R1 = 256,
    L1 = 512,
    R2 = 1024,
    L2 = 2048,
    R3 = 4096,
    L3 = 8192,
    Start = 16384,
    Back = 32768,
    LeftStick_Left = 65536,
    LeftStick_Right = 131072,
    LeftStick_Up = 262144,
    LeftStick_Down = 524288,
    RightStick_Left = 1048576,
    RightStick_Right = 2097152,
    RightStick_Up = 4194304,
    RightStick_Down = 8388608,
    DPad = 240,
    LeftStick = 983040,
    RightStick = 14680064,
    Any = 3855,
};

