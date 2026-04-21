#pragma once
#include "CoreMinimal.h"
#include "GameOnlineUserSettings.h"
#include "GameOnlineFirstMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineFirstMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserSettings OnlineUserSettings;
    
    ABRAMS_API FGameOnlineFirstMessage();
};

