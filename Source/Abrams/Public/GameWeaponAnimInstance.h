#pragma once
#include "CoreMinimal.h"
#include "GameAnimInstance.h"
#include "GameWeaponAnimInstance.generated.h"

UCLASS(Abstract, Blueprintable, NonTransient)
class ABRAMS_API UGameWeaponAnimInstance : public UGameAnimInstance {
    GENERATED_BODY()
public:
    UGameWeaponAnimInstance();

};

