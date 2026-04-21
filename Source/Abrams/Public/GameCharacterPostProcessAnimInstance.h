#pragma once
#include "CoreMinimal.h"
#include "EGameActorPostProcessAnimLOD.h"
#include "EGameActorPostProcessAnimMode.h"
#include "GamePostProcessAnimInstance.h"
#include "GameCharacterPostProcessAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UGameCharacterPostProcessAnimInstance : public UGamePostProcessAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameActorPostProcessAnimLOD AnimLOD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameActorPostProcessAnimMode AnimMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UniqueAlpha;
    
    UGameCharacterPostProcessAnimInstance();

};

