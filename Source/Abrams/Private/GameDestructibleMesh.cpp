#include "GameDestructibleMesh.h"
#include "Components/SceneComponent.h"
#include "GameDestructibleReactioner.h"

AGameDestructibleMesh::AGameDestructibleMesh(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->RootSceneComponent = (USceneComponent*)RootComponent;
    this->Reactioner = CreateDefaultSubobject<UGameDestructibleReactioner>(TEXT("Reactioner"));
}


