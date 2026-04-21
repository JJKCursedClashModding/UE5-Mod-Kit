#pragma once
#include "CoreMinimal.h"
#include "EGameBattleNotifyWidgetRequestState.generated.h"

UENUM(BlueprintType)
enum class EGameBattleNotifyWidgetRequestState : uint8 {
    Unused,
    DrawCheck,
    WaitOpen,
    FinishedOpen,
};

