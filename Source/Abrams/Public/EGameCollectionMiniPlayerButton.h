#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionMiniPlayerButton.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionMiniPlayerButton : uint8 {
    None,
    Back,
    Next,
    Start,
    Repeat,
};

