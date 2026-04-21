#pragma once
#include "CoreMinimal.h"
#include "EGameShikigamiChaseType.generated.h"

UENUM(BlueprintType)
enum class EGameShikigamiChaseType : uint8 {
    Summoner,
    Summoner_LeftBack,
    Target,
    Own,
};

