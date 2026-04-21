#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionMenu.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionMenu : uint8 {
    None,
    MainMenu,
    Mode,
    Window,
    Replay,
    Script,
};

