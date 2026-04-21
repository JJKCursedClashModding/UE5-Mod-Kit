#pragma once
#include "CoreMinimal.h"
#include "EGameVsEnemyBattlePartnerType.generated.h"

UENUM(BlueprintType)
enum class EGameVsEnemyBattlePartnerType : uint8 {
    None,
    Back,
    Offline,
    Online,
    CharacterSettings,
    Ranking,
};

