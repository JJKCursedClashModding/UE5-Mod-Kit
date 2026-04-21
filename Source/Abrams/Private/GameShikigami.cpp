#include "GameShikigami.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameCapsuleComponent.h"

AGameShikigami::AGameShikigami(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UGameCapsuleComponent>(TEXT("CollisionCylinder"));
    this->Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh0"));
    this->CapsuleComponent = (UGameCapsuleComponent*)RootComponent;
    this->AnimInstance = NULL;
    this->StatusController = NULL;
    this->MovementController = NULL;
    this->ActionController = NULL;
    this->BoneController = NULL;
    this->MaterialController = NULL;
    this->TargetController = NULL;
    this->EffectController = NULL;
    this->AttackCollisionKeeper = NULL;
    this->DamageCollisionKeeper = NULL;
    this->Mesh->SetupAttachment(RootComponent);
}


