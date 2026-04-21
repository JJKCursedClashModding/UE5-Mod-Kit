#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterAnimMontageType.h"
#include "AbramsSequencerPlayUniqueAnimationInfo.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerPlayUniqueAnimationInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterAnimMontageType AnimMontageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* Sequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotNodeName;
    
    FAbramsSequencerPlayUniqueAnimationInfo();
};

