#pragma once
#include "CoreMinimal.h"
#include "EGameLobbyFindMenu.generated.h"

UENUM(BlueprintType)
enum class EGameLobbyFindMenu : uint8 {
    None,
    Find_Friend,
    Find_ID,
    Find_Conditions,
    CharacterSelect,
    Back,
};

