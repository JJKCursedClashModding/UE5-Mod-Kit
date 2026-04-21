#pragma once
#include "CoreMinimal.h"
#include "Engine/PostProcessVolume.h"
#include "SequencerActorInterface.h"
#include "AbramsSequencerPostProcessVolume.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerPostProcessVolume : public APostProcessVolume, public ISequencerActorInterface {
    GENERATED_BODY()
public:
    AAbramsSequencerPostProcessVolume(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

