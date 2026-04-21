#pragma once
#include "CoreMinimal.h"
#include "GameSceneCapture2D.h"
#include "SequencerActorInterface.h"
#include "AbramsSequencerSceneCaptureActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerSceneCaptureActor : public AGameSceneCapture2D, public ISequencerActorInterface {
    GENERATED_BODY()
public:
    AAbramsSequencerSceneCaptureActor(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

