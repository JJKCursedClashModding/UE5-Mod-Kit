#include "GameNPC.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"

AGameNPC::AGameNPC(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh0"));
    this->MaterialController = NULL;
    this->Mesh->SetupAttachment(RootComponent);
}


