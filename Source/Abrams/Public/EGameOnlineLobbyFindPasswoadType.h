#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineLobbyFindPasswoadType.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineLobbyFindPasswoadType : uint8 {
    SetOnly,
    NotSetOnly,
    Either,
};

