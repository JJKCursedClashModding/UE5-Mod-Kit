#include "GameCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameCapsuleComponent.h"

AGameCharacter::AGameCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UGameCapsuleComponent>(TEXT("CollisionCylinder"));
    this->Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh0"));
    this->CapsuleComponent = (UGameCapsuleComponent*)RootComponent;
    this->AnimInstance = NULL;
    this->PostProcessAnimInstance = NULL;
    this->InputData = NULL;
    this->VirtualCamera = NULL;
    this->MovementController = NULL;
    this->StatusController = NULL;
    this->FacialController = NULL;
    this->ActionController = NULL;
    this->BoneController = NULL;
    this->MaterialController = NULL;
    this->TargetController = NULL;
    this->EffectController = NULL;
    this->WeaponController = NULL;
    this->ShikigamiController = NULL;
    this->TransformationController = NULL;
    this->Brain = NULL;
    this->OperationController = NULL;
    this->ChatController = NULL;
    this->AttackCollisionKeeper = NULL;
    this->DamageCollisionKeeper = NULL;
    this->ClashingCollisionKeeper = NULL;
    this->Mesh->SetupAttachment(RootComponent);
}


