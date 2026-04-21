#pragma once
#include "CoreMinimal.h"
#include "EDebugMenuViewMode.generated.h"

UENUM(BlueprintType)
enum class EDebugMenuViewMode : uint8 {
    Lit,
    Unlit,
    Wireframe,
    LightComplexity,
    ShaderComplexity,
    LODColoration,
};

