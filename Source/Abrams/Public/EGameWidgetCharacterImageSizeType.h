#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetCharacterImageSizeType.generated.h"

UENUM(BlueprintType)
enum class EGameWidgetCharacterImageSizeType : uint8 {
    Normal,
    Small,
    VerySmall,
    Tiny,
    VeryTiny,
    Max = Normal,
    Min = VeryTiny,
};

