#pragma once
#include "CoreMinimal.h"
#include "EGameConfigCategoryFlag.generated.h"

UENUM()
enum class EGameConfigCategoryFlag : uint32 {
    None,
    Game,
    SoundVolume,
    KeyBind = 4,
    KeyboardBind = 8,
    Language = 16,
    Graphic = 32,
    Copyright = 64,
    Brightness = 128,
    Help = 256,
    Tutorial = 512,
    Matching = 1024,
    All = 4294967295,
};

