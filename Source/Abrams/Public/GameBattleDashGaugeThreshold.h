#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameBattleDashGaugeThreshold.generated.h"

USTRUCT(BlueprintType)
struct FGameBattleDashGaugeThreshold {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Rate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor Color;
    
    ABRAMS_API FGameBattleDashGaugeThreshold();
};

