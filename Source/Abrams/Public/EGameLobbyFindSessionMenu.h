#pragma once
#include "CoreMinimal.h"
#include "EGameLobbyFindSessionMenu.generated.h"

UENUM(BlueprintType)
enum class EGameLobbyFindSessionMenu : uint8 {
    None,
    FindSession,
    JoinSession,
    Exit,
    ExitForCondition,
    ExitForId,
};

