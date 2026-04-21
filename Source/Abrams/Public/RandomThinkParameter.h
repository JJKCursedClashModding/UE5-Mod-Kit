#pragma once
#include "CoreMinimal.h"
#include "BehaviorParameter.h"
#include "RandomThinkParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FRandomThinkParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBehaviorParameter> BehaviorParameterArray;
    
    FRandomThinkParameter();
};

