#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineSendMessageType.h"
#include "GameOnlineSendMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineSendMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlineSendMessageType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    ABRAMS_API FGameOnlineSendMessage();
};

