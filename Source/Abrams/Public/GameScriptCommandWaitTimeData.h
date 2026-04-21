#pragma once
#include "CoreMinimal.h"
#include "GameScriptCommandWaitTimeData.generated.h"

USTRUCT(BlueprintType)
struct FGameScriptCommandWaitTimeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitTime;
    
    ABRAMS_API FGameScriptCommandWaitTimeData();
};

