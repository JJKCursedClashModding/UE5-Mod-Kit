#pragma once
#include "CoreMinimal.h"
#include "GameOnlineEveryoneReadyMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineEveryoneReadyMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InputDelayCount;
    
    ABRAMS_API FGameOnlineEveryoneReadyMessage();
};

