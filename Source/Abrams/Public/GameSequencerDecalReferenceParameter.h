#pragma once
#include "CoreMinimal.h"
#include "GameSequencerDecalReferenceParameter.generated.h"

USTRUCT(BlueprintType)
struct FGameSequencerDecalReferenceParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_Decal;
    
    ABRAMS_API FGameSequencerDecalReferenceParameter();
};

