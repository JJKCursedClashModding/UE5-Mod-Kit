#include "GameDestructibleDecal.h"
#include "GameBoxComponent_Destructible.h"
#include "GameDestructibleReactioner.h"

AGameDestructibleDecal::AGameDestructibleDecal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UGameBoxComponent_Destructible>(TEXT("CollisionBox"));
    this->BoxComponent = (UGameBoxComponent*)RootComponent;
    this->Reactioner = CreateDefaultSubobject<UGameDestructibleReactioner>(TEXT("Reactioner"));
    this->Defence = 0.00f;
    this->bActionCameraObstacle = false;
}


