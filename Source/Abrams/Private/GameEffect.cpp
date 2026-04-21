#include "GameEffect.h"
#include "Components/SceneComponent.h"

AGameEffect::AGameEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->EffectMovement = NULL;
    this->AttackCollisionKeeper = NULL;
    this->DamageCollisionKeeper = NULL;
    this->NullifiesDamageCollisionKeeper = NULL;
}

void AGameEffect::OnComponentBeginOverlapEffect(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


