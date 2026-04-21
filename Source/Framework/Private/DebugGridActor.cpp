#include "DebugGridActor.h"
#include "ProceduralMeshComponent.h"

ADebugGridActor::ADebugGridActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Grid"));
    this->Grid = (UProceduralMeshComponent*)RootComponent;
}


