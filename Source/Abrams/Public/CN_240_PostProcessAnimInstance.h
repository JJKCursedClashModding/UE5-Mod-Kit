#pragma once
#include "CoreMinimal.h"
#include "GameCharacterPostProcessAnimInstance.h"
#include "CN_240_PostProcessAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UCN_240_PostProcessAnimInstance : public UGameCharacterPostProcessAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotateAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RingRotateAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RingRotate;
    
public:
    UCN_240_PostProcessAnimInstance();

};

