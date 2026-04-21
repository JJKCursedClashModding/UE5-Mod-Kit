#pragma once
#include "CoreMinimal.h"
#include "BehaviorParameter.h"
#include "BehaviorThinkParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FBehaviorThinkParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBehaviorParameter> BehaviorParameterArray;
    
    FBehaviorThinkParameter();
};

