#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterIndex.h"
#include "GameOnlineUserSettings.h"
#include "GameOnlineReturnFirstMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineReturnFirstMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NetworkId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterIndex PlayableCharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> RandomStreamSeedArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameOnlineUserSettings> OnlineUserSettingsArray;
    
    ABRAMS_API FGameOnlineReturnFirstMessage();
};

