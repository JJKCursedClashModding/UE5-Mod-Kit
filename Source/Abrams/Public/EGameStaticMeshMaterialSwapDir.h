#pragma once
#include "CoreMinimal.h"
#include "EGameStaticMeshMaterialSwapDir.generated.h"

UENUM(BlueprintType)
enum class EGameStaticMeshMaterialSwapDir : uint8 {
    None,
    Swap,
    Back,
};

