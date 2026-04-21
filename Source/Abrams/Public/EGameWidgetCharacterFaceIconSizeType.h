#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetCharacterFaceIconSizeType.generated.h"

UENUM(BlueprintType)
enum class EGameWidgetCharacterFaceIconSizeType : uint8 {
    Normal,
    Small,
    VerySmall,
    Tiny,
    VeryTiny,
    Max = Normal,
    Min = VeryTiny,
};

