#pragma once
#include "CoreMinimal.h"
#include "GameSequencerAnimationReferenceParameter.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct FGameSequencerAnimationReferenceParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CommonAnimationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimSequence> AnimSequence;
    
    ABRAMS_API FGameSequencerAnimationReferenceParameter();
};

