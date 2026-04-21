#pragma once
#include "CoreMinimal.h"
#include "EGameNicknameType.generated.h"

UENUM(BlueprintType)
enum class EGameNicknameType : uint8 {
    None,
    Top,
    Bottom,
    Invalid = 255,
};

