#pragma once
#include "CoreMinimal.h"
#include "EGameTitleAgreementType.generated.h"

UENUM(BlueprintType)
enum class EGameTitleAgreementType : uint8 {
    None,
    EULA,
    PP,
    DATAUSE,
    OSS,
};

