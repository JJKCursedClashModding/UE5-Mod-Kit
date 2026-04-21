#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineSendMessageType.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineSendMessageType : uint8 {
    System,
    Chat,
    Stamp,
    Invalid = 255,
};

