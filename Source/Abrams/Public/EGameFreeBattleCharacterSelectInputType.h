#pragma once
#include "CoreMinimal.h"
#include "EGameFreeBattleCharacterSelectInputType.generated.h"

UENUM(BlueprintType)
enum class EGameFreeBattleCharacterSelectInputType : uint8 {
    None,
    Focus,
    OptionBox,
};

