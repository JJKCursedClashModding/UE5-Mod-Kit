#pragma once
#include "CoreMinimal.h"
#include "EGameSystemDialogType.generated.h"

UENUM(BlueprintType)
enum class EGameSystemDialogType : uint8 {
    None,
    Ok,
    YesNo,
    ErrorOk,
    ErrorYesNo,
};

