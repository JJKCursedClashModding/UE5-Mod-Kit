#pragma once
#include "CoreMinimal.h"
#include "EGameVisualLobbyTopMenuFlag.generated.h"

UENUM()
enum class EGameVisualLobbyTopMenuFlag : uint32 {
    None,
    RoomInfo,
    CharacterSelect,
    BattleModeSelect = 4,
    BattleModeView = 8,
    FunctionSettings = 16,
    CommandList = 32,
    LeaveRoom = 64,
    ExitMenu = 128,
    InviteFriend = 256,
    All = 4294967295,
};
