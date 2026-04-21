#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameSequencerGlobalOffsetParameter.generated.h"

USTRUCT(BlueprintType)
struct FGameSequencerGlobalOffsetParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector OffsetLocation;
    
    ABRAMS_API FGameSequencerGlobalOffsetParameter();
};

