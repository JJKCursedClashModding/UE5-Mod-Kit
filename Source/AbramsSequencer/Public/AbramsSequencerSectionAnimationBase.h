#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSectionAnimationBase.generated.h"

class UAnimMontage;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSectionAnimationBase : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FallbackDummyMontage;
    
    UAbramsSequencerSectionAnimationBase();

};

