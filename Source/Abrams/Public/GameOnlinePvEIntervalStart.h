#pragma once
#include "CoreMinimal.h"
#include "GameOnlinePvEIntervalStart.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlinePvEIntervalStart {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExtraMissionPoint;
    
    ABRAMS_API FGameOnlinePvEIntervalStart();
};

