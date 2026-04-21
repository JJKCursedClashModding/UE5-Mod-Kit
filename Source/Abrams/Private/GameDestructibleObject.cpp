#include "GameDestructibleObject.h"
#include "GameBoxComponent_Destructible.h"

AGameDestructibleObject::AGameDestructibleObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UGameBoxComponent_Destructible>(TEXT("CollisionBox"));
    this->bIsBreakEffectForceFrontDirection = false;
    this->RelationalAnimSequence = NULL;
    this->Defence = 0.00f;
    this->FadeOutTime = 1.00f;
    this->bCanStepUpOn = true;
    this->bBreakCanStepUpOn = true;
    this->bActionCameraObstacle = true;
    this->bReceivesDecals = false;
    this->BoxComponent = (UGameBoxComponent*)RootComponent;
}


