#pragma once
#include "CoreMinimal.h"
#include "EGameTrapActionType.generated.h"

UENUM(BlueprintType)
enum class EGameTrapActionType : uint8 {
    None,
    VolcanoHoming,
    VolcanoOneShot,
    VolcanoTrigger,
    FlowerMachineGun,
    PlantRootMove,
    PlantWall,
    BodyRepel,
    Uzumaki,
    IceWall,
    Invalid = 255,
};

