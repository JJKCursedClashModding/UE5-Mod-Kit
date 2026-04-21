#pragma once
#include "CoreMinimal.h"
#include "EApplicationLanguage.generated.h"

UENUM(BlueprintType)
enum class EApplicationLanguage : uint8 {
    Ja,
    En,
    Fr,
    Es,
    De,
    It,
    Ko,
    Zh_Hant,
    Zh_Hans,
    Pt,
    Es_LA,
    Ar,
    Ind,
    Pl,
    Ru,
    Th,
    Invalid = 255,
};

