#pragma once
#include "CoreMinimal.h"
#include "EGameBattleLogPassiveType.generated.h"

UENUM(BlueprintType)
enum class EGameBattleLogPassiveType : uint8 {
    None,
    Send,
    Receive,
    Invalid = 255,
};

