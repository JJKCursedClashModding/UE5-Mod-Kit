#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GamePostProcessAnimInstance.generated.h"

UCLASS(Abstract, Blueprintable, NonTransient)
class ABRAMS_API UGamePostProcessAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UGamePostProcessAnimInstance();

};

