#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetFontLanguageType.generated.h"

UENUM()
enum class EGameWidgetFontLanguageType : int8 {
    Invalid,
    Ja,
    EnEurope,
    Ko,
    Zh_Hant,
    Zh_Hans,
    Ar,
    Th,
    Max,
};

