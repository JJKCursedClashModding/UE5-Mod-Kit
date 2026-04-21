#pragma once
#include "CoreMinimal.h"
#include "GameAnimationAsset.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameAnimationAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Asset;
    
    FGameAnimationAsset();
};

