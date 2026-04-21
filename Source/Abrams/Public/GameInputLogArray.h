#pragma once
#include "CoreMinimal.h"
#include "GameInputLog.h"
#include "GameInputLogArray.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameInputLogArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameInputLog> ValueArray;
    
    FGameInputLogArray();
};

