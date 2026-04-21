#pragma once
#include "CoreMinimal.h"
#include "EDebugMenuCharacterRecordValueType.generated.h"

UENUM(BlueprintType)
enum class EDebugMenuCharacterRecordValueType : uint8 {
    Appearance,
    PvPUse,
    PvEUse,
    BattleUse,
};

