#pragma once
#include "CoreMinimal.h"
#include "Animation/PoseSnapshot.h"
#include "GameActorAnimInstance.h"
#include "GameCharacterAfterImageAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UGameCharacterAfterImageAnimInstance : public UGameActorAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseSnapshot Snapshot;
    
    UGameCharacterAfterImageAnimInstance();

};

