#pragma once
#include "CoreMinimal.h"
#include "EGameEffectTag.generated.h"

UENUM(BlueprintType)
enum class EGameEffectTag : uint8 {
    None,
    PlayableHit,
    NonPlayableHit,
};

