#include "GameBattleLockonDirectionActor.h"
#include "Components/StaticMeshComponent.h"

AGameBattleLockonDirectionActor::AGameBattleLockonDirectionActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UI_LockonAlert_Cursor"));
    this->Mesh = (UStaticMeshComponent*)RootComponent;
    this->MaterialController = NULL;
}


