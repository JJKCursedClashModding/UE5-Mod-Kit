#pragma once
#include "CoreMinimal.h"
#include "EGameShikigamiFoot.generated.h"

UENUM(BlueprintType)
enum class EGameShikigamiFoot : uint8 {
    Left_Hand,
    Right_Hand,
    Left_Ankle,
    Right_Ankle,
    Invalid = 255,
};

