#pragma once
#include "CoreMinimal.h"
#include "SequencerCameraRootActor.h"
#include "AbramsSequencerCameraRootActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerCameraRootActor : public ASequencerCameraRootActor {
    GENERATED_BODY()
public:
    AAbramsSequencerCameraRootActor(const FObjectInitializer& ObjectInitializer);

};

