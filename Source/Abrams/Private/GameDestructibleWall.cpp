#include "GameDestructibleWall.h"
#include "GameBoxComponent_InvisibleWall.h"
#include "GameDestructibleReactioner.h"

AGameDestructibleWall::AGameDestructibleWall(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UGameBoxComponent_InvisibleWall>(TEXT("CollisionBox"));
    this->BoxComponent = (UGameBoxComponent_InvisibleWall*)RootComponent;
    this->Reactioner = CreateDefaultSubobject<UGameDestructibleReactioner>(TEXT("Reactioner"));
}


