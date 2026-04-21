#pragma once
#include "CoreMinimal.h"
#include "GameLevelObject.h"
#include "SequencerActorInterface.h"
#include "AbramsSequencerLevelObject.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerLevelObject : public AGameLevelObject, public ISequencerActorInterface {
    GENERATED_BODY()
public:
    AAbramsSequencerLevelObject(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

