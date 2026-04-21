#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterIndex.h"
#include "GameOnlineUserCommunicateInfo.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineUserCommunicateInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameCharacterIndex> CommunicateBlockedCharacterIndexArray;
    
    ABRAMS_API FGameOnlineUserCommunicateInfo();
};

