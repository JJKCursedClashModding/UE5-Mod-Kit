#pragma once
#include "CoreMinimal.h"
#include "SequencerCameraFocusActor.h"
#include "AbramsSequencerCameraFocusActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerCameraFocusActor : public ASequencerCameraFocusActor {
    GENERATED_BODY()
public:
    AAbramsSequencerCameraFocusActor(const FObjectInitializer& ObjectInitializer);

};

