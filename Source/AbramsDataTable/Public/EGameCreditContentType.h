#pragma once
#include "CoreMinimal.h"
#include "EGameCreditContentType.generated.h"

UENUM(BlueprintType)
enum class EGameCreditContentType : uint8 {
    None,
    Title,
    Company,
    Section,
    Job,
    Name,
    Image,
    Space,
    Invalid = 255,
};

