#pragma once
#include "CoreMinimal.h"
#include "EGameShikigamiHitCharacterType.generated.h"

UENUM(BlueprintType)
enum class EGameShikigamiHitCharacterType : uint8 {
    All,
    WithoutSummoner,
    ShikigamiOnly,
    None,
};

