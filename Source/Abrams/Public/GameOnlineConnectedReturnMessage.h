#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineConnectStatus.h"
#include "EGameOnlineStatusCode.h"
#include "GameOnlineConnectedReturnMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineConnectedReturnMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlineConnectStatus ConnectStatus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlineStatusCode StatusCode;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 BeaconId;
    
    ABRAMS_API FGameOnlineConnectedReturnMessage();
};

