#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetBindingVowsDifficultType.generated.h"

UENUM(BlueprintType)
enum class EGameWidgetBindingVowsDifficultType : uint8 {
    Invalid,
    Easy,
    Medium,
    Hard,
    Special,
};

