#pragma once
#include "CoreMinimal.h"
#include "GameOnlineReadyMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineReadyMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsReady;
    
    ABRAMS_API FGameOnlineReadyMessage();
};

