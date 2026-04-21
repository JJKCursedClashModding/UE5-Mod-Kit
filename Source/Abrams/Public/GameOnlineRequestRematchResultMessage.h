#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineRematchType.h"
#include "GameOnlineRequestRematchResultMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineRequestRematchResultMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlineRematchType RematchType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PartnerUserId;
    
    ABRAMS_API FGameOnlineRequestRematchResultMessage();
};

