#include "GameWeapon.h"
#include "Components/SceneComponent.h"

AGameWeapon::AGameWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->Mesh = NULL;
    this->MaterialController = NULL;
}


