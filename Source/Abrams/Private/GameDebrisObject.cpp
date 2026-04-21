#include "GameDebrisObject.h"

AGameDebrisObject::AGameDebrisObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReceivesDecals = false;
    this->bSkipShowReaction = false;
}


