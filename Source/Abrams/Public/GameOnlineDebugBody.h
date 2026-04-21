#pragma once
#include "CoreMinimal.h"
#include "GameOnlineDebugData.h"
#include "GameOnlineDebugBody.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineDebugBody {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineDebugData DebugDataArray[4];
    
    ABRAMS_API FGameOnlineDebugBody();
};

