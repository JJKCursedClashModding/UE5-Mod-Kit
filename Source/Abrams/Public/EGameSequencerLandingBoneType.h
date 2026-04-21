#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerLandingBoneType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerLandingBoneType : uint8 {
    None,
    L_Toe,
    R_Toe,
    L_Hand,
    R_Hand,
};

