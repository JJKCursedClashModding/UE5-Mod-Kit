#pragma once
#include "CoreMinimal.h"
#include "EGameCameraMode.generated.h"

UENUM(BlueprintType)
enum class EGameCameraMode : uint8 {
    Min,
    Default = Min,
    Battle,
    BattleFinish,
    BattleFinishSimple,
    BattleResult,
    BattleFixed,
    Sequencer,
    Max = Sequencer,
    Num,
    Invalid = 255,
};

