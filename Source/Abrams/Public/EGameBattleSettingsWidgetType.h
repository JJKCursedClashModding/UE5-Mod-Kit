#pragma once
#include "CoreMinimal.h"
#include "EGameBattleSettingsWidgetType.generated.h"

UENUM(BlueprintType)
enum class EGameBattleSettingsWidgetType : uint8 {
    None,
    OnlineActive,
    OnlineWaitPartner,
    OnlineWaitOpenWidget,
    OnlineWaitRivalTeam,
    Offline,
};

