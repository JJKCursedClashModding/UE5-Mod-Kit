#include "GameTrap.h"
#include "Components/SceneComponent.h"

AGameTrap::AGameTrap(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->Mesh = NULL;
    this->ActionController = NULL;
    this->MaterialController = NULL;
    this->AttackCollisionKeeper = NULL;
    this->DamageCollisionKeeper = NULL;
    this->NullifiesDamageCollisionKeeper = NULL;
}


