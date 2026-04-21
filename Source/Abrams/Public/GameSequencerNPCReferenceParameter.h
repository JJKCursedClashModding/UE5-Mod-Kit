#pragma once
#include "CoreMinimal.h"
#include "GameSequencerNPCReferenceParameter.generated.h"

USTRUCT(BlueprintType)
struct FGameSequencerNPCReferenceParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_NPC;
    
    ABRAMS_API FGameSequencerNPCReferenceParameter();
};

