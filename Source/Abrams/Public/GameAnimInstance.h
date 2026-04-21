#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameAnimationAsset.h"
#include "GameAnimInstance.generated.h"

UCLASS(Abstract, Blueprintable, NonTransient)
class ABRAMS_API UGameAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameAnimationAsset> AssetMap;
    
public:
    UGameAnimInstance();

};

