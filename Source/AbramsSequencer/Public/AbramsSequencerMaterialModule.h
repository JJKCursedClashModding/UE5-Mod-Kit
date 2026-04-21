#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerActorReferenceModule.h"
#include "AbramsSequencerMaterialModule.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerMaterialModule : public UAbramsSequencerActorReferenceModule {
    GENERATED_BODY()
public:
    UAbramsSequencerMaterialModule();

};

