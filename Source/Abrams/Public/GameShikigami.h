#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameShikigami.generated.h"

class UGameCapsuleComponent;
class UGameCollisionKeeper;
class UGameShikigamiActionController;
class UGameShikigamiAnimInstance;
class UGameShikigamiBoneController;
class UGameShikigamiEffectController;
class UGameShikigamiMaterialController;
class UGameShikigamiMovementController;
class UGameShikigamiStatusController;
class UGameShikigamiTargetController;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameShikigami : public AGameActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameShikigamiAnimInstance* AnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameShikigamiStatusController* StatusController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameShikigamiMovementController* MovementController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameShikigamiActionController* ActionController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameShikigamiBoneController* BoneController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameShikigamiMaterialController* MaterialController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameShikigamiTargetController* TargetController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameShikigamiEffectController* EffectController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* AttackCollisionKeeper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* DamageCollisionKeeper;
    
public:
    AGameShikigami(const FObjectInitializer& ObjectInitializer);

};

