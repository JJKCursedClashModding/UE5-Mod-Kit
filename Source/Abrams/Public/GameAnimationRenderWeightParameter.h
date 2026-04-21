#pragma once
#include "CoreMinimal.h"
#include "GameAnimationRenderWeightParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameAnimationRenderWeightParameter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeightBlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeightBlendOut;
    
public:
    FGameAnimationRenderWeightParameter();
};

