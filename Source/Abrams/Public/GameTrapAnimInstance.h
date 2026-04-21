#pragma once
#include "CoreMinimal.h"
#include "GameAnimInstance.h"
#include "GameTrapAnimInstance.generated.h"

UCLASS(Abstract, Blueprintable, NonTransient)
class ABRAMS_API UGameTrapAnimInstance : public UGameAnimInstance {
    GENERATED_BODY()
public:
    UGameTrapAnimInstance();

};

