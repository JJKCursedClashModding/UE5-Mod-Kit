#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineReceivedFlag.generated.h"

UENUM()
enum class EGameOnlineReceivedFlag {
    None,
    FirstMessage,
    UserSettings,
    ReadyMessage = 4,
    ResumeSyncInput = 8,
    Rematch = 16,
    RestartVisualLobby = 32,
    SyncWait = 64,
    StartPvEInterval = 128,
    UpdatePvEBindingVows = 256,
    SkipAppearance = 512,
    StartCharacterSelect = 1024,
    AgreeBattle = 2048,
};

