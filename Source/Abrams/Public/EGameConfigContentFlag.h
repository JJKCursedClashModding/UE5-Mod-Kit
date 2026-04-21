#pragma once
#include "CoreMinimal.h"
#include "EGameConfigContentFlag.generated.h"

UENUM()
enum class EGameConfigContentFlag : uint32 {
    None,
    Language,
    All = 4294967295,
};
