#pragma once
#include "CoreMinimal.h"
#include "EDebugScriptPage.generated.h"

UENUM(BlueprintType)
enum class EDebugScriptPage : uint8 {
    Top,
    CategorySelect,
    ScriptSelect,
    Max,
};

