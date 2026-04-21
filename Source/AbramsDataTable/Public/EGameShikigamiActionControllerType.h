#pragma once
#include "CoreMinimal.h"
#include "EGameShikigamiActionControllerType.generated.h"

UENUM(BlueprintType)
enum class EGameShikigamiActionControllerType : uint8 {
    None,
    CN_010,
    CN_020,
    CN_030,
    CN_040,
    CN_050,
    CN_070,
    CN_080,
    CN_110,
    CN_180,
    CN_200,
    CN_220,
    CN_231,
    CN_270,
    CN_272,
    CN_280,
    Invalid = 255,
};

