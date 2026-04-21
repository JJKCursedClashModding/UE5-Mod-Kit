#pragma once
#include "CoreMinimal.h"
#include "SequencerCameraTransformActor.h"
#include "AbramsSequencerCameraTransformActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerCameraTransformActor : public ASequencerCameraTransformActor {
    GENERATED_BODY()
public:
    AAbramsSequencerCameraTransformActor(const FObjectInitializer& ObjectInitializer);

};

