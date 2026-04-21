#pragma once
#include "CoreMinimal.h"
#include "ELobbyPhaseStartMode.generated.h"

UENUM(BlueprintType)
enum class ELobbyPhaseStartMode : uint8 {
    Top,
    RestartLobby,
    RecreateLobby,
    InviteSession,
    Invalid = 255,
};

