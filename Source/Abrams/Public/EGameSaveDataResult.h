#pragma once
#include "CoreMinimal.h"
#include "EGameSaveDataResult.generated.h"

UENUM(BlueprintType)
enum class EGameSaveDataResult : uint8 {
    OK,
    DoesNotExist,
    Corrupt,
    UnspecifiedError,
};

