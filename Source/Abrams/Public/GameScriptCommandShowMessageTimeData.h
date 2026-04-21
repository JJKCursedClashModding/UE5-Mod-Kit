#pragma once
#include "CoreMinimal.h"
#include "GameScriptCommandShowMessageTimeData.generated.h"

USTRUCT(BlueprintType)
struct FGameScriptCommandShowMessageTimeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitTime;
    
    ABRAMS_API FGameScriptCommandShowMessageTimeData();
};

