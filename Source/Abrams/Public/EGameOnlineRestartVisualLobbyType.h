#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineRestartVisualLobbyType.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineRestartVisualLobbyType : uint8 {
    NewConnection,
    ChangeCharacter,
    Invalid = 255,
};

