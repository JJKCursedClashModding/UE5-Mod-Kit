#include "GameBattleArea.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"

AGameBattleArea::AGameBattleArea(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    this->AppearanceTransformArray.AddDefaulted(2);
    this->ResultTransformArray.AddDefaulted(1);
    this->TagComboTransformArray.AddDefaulted(1);
    this->TagComboReturnTransformArray.AddDefaulted(1);
    this->CharacterTransform1vs1Array.AddDefaulted(2);
    this->CharacterTransform1vs2Array.AddDefaulted(3);
    this->CharacterTransform1vs3Array.AddDefaulted(4);
    this->CharacterTransform1vs4Array.AddDefaulted(5);
    this->CharacterTransform1vs5Array.AddDefaulted(6);
    this->CharacterTransform2vs1Array.AddDefaulted(3);
    this->CharacterTransform2vs2Array.AddDefaulted(4);
    this->CharacterTransform2vs3Array.AddDefaulted(5);
    this->CharacterTransform2vs4Array.AddDefaulted(6);
    this->CharacterTransform3vs1Array.AddDefaulted(4);
    this->CharacterTransform3vs2Array.AddDefaulted(5);
    this->CharacterTransform3vs3Array.AddDefaulted(6);
    this->DomainExpansionTransform = CreateDefaultSubobject<USceneComponent>(TEXT("DomainExpansion"));
    this->DomainExpansionTransform->SetupAttachment(RootComponent);
}


