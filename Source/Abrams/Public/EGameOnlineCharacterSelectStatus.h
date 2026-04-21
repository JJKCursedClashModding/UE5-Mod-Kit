#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineCharacterSelectStatus.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineCharacterSelectStatus : uint8 {
    Selecting,
    Waiting,
    AgreeBattle,
    AgreeBattleHigher,
    Invalid = 255,
};

