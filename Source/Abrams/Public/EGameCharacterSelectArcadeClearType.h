#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSelectArcadeClearType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterSelectArcadeClearType : uint8 {
    None,
    Clear,
    NoContinueClear,
    NoContinueDifficultyClear,
};

