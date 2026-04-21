#pragma once
#include "CoreMinimal.h"
#include "EGameCustomizeChatDirectionType.generated.h"

UENUM(BlueprintType)
enum class EGameCustomizeChatDirectionType : uint8 {
    Up,
    Down,
    Left,
    Right,
};

