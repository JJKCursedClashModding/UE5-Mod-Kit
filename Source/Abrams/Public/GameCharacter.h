#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameCharacter.generated.h"

class UGameCapsuleComponent;
class UGameCharacterActionController;
class UGameCharacterAnimInstance;
class UGameCharacterBoneController;
class UGameCharacterBrain;
class UGameCharacterChatController;
class UGameCharacterEffectController;
class UGameCharacterFacialController;
class UGameCharacterInputData;
class UGameCharacterMaterialController;
class UGameCharacterMovementController;
class UGameCharacterOperationController;
class UGameCharacterPostProcessAnimInstance;
class UGameCharacterShikigamiController;
class UGameCharacterStatusController;
class UGameCharacterTargetController;
class UGameCharacterTransformationController;
class UGameCharacterVirtualCamera;
class UGameCharacterWeaponController;
class UGameCollisionKeeper;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameCharacter : public AGameActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterAnimInstance* AnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterPostProcessAnimInstance* PostProcessAnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterInputData* InputData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterVirtualCamera* VirtualCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterMovementController* MovementController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterStatusController* StatusController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterFacialController* FacialController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterActionController* ActionController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterBoneController* BoneController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterMaterialController* MaterialController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterTargetController* TargetController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterEffectController* EffectController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterWeaponController* WeaponController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterShikigamiController* ShikigamiController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterTransformationController* TransformationController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterBrain* Brain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterOperationController* OperationController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterChatController* ChatController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* AttackCollisionKeeper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* DamageCollisionKeeper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* ClashingCollisionKeeper;
    
public:
    AGameCharacter(const FObjectInitializer& ObjectInitializer);

};

