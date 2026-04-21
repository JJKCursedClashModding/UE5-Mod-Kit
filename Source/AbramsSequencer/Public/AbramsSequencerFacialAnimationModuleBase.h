#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerActorAnimationModule.h"
#include "AbramsSequencerFacialAnimationModuleBase.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerFacialAnimationModuleBase : public UAbramsSequencerActorAnimationModule {
    GENERATED_BODY()
public:
    UAbramsSequencerFacialAnimationModuleBase();

};

