#pragma once
#include "CoreMinimal.h"
#include "EGameCustomizeType.generated.h"

UENUM(BlueprintType)
enum class EGameCustomizeType : uint8 {
    None,
    Customize,
    Chat,
    PlayerCard,
    CharaView,
};

