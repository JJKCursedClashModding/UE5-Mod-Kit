#include "AbramsSequencerParallaxMaterialActor.h"
#include "Components/DecalComponent.h"
#include "Components/SceneComponent.h"

AAbramsSequencerParallaxMaterialActor::AAbramsSequencerParallaxMaterialActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->X = -1;
    this->Y = 1;
    this->Z = 1;
    this->Decal = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
    this->MaterialInstance = NULL;
    this->OpacityTimer = NULL;
    this->EmissiveTimer = NULL;
    this->MaterialInstanceDynamic = NULL;
    this->Decal->SetupAttachment(RootComponent);
}

void AAbramsSequencerParallaxMaterialActor::OnUpdateOpacityTimer(const float Output) {
}

void AAbramsSequencerParallaxMaterialActor::OnUpdateEmissiveTimer(const float Output) {
}


