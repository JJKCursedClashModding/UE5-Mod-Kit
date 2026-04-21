#pragma once
#include "CoreMinimal.h"
#include "GamePvEItemSettings.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGamePvEItemSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HealPoint;
    
    FGamePvEItemSettings();
};

