#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameActorBoneController.generated.h"

class UAnimMontage;

UCLASS(Blueprintable)
class ABRAMS_API UGameActorBoneController : public UObject {
    GENERATED_BODY()
public:
    UGameActorBoneController();

protected:
    UFUNCTION(BlueprintCallable)
    void OnEndMontage(UAnimMontage* InAnimMontage, bool bInInterrupted);
    
};

