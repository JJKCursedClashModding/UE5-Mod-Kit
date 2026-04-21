#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetCharacterCaptureBackgroundColorType.generated.h"

UENUM(BlueprintType)
enum class EGameWidgetCharacterCaptureBackgroundColorType : uint8 {
    SolidColor,
    Gradiation_UpToDown,
    Gradiation_DownToUp,
};

