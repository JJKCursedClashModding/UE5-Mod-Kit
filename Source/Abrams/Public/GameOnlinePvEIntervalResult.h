#pragma once
#include "CoreMinimal.h"
#include "GameOnlinePvEBindingVows.h"
#include "GameOnlinePvEIntervalAction.h"
#include "GameOnlinePvEIntervalResult.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlinePvEIntervalResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameOnlinePvEIntervalAction> IntervalActionArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameOnlinePvEBindingVows> UpdateBindingVowsArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> ExtraMissionPointArray;
    
    ABRAMS_API FGameOnlinePvEIntervalResult();
};

