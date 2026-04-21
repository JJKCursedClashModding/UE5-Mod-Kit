#pragma once
#include "CoreMinimal.h"
#include "EGameLobbyTopMenu.generated.h"

UENUM(BlueprintType)
enum class EGameLobbyTopMenu : uint8 {
    None,
    CreateSession,
    FindSession,
    CharacterSelect,
    Exit,
};

