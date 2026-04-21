#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameOnlinePingMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlinePingMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime SendPingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> PingArray;
    
    ABRAMS_API FGameOnlinePingMessage();
};

