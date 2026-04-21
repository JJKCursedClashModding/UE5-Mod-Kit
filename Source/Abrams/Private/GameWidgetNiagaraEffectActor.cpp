#include "GameWidgetNiagaraEffectActor.h"
#include "Components/SceneComponent.h"

AGameWidgetNiagaraEffectActor::AGameWidgetNiagaraEffectActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
}


