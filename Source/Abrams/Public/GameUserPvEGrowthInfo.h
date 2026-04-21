#pragma once
#include "CoreMinimal.h"
#include "GameUserPvEGrowthInfo.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameUserPvEGrowthInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Experience;
    
    FGameUserPvEGrowthInfo();
};

