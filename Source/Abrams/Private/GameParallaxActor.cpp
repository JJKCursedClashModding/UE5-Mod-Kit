#include "GameParallaxActor.h"

AGameParallaxActor::AGameParallaxActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaterialInstance = NULL;
    this->RotationScaleX = -1.00f;
    this->RotationScaleY = 1.00f;
    this->RotationScaleZ = 1.00f;
}


