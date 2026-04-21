#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineGameMode.h"
#include "GameOnlineVisualLobbyNextGameMode.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineVisualLobbyNextGameMode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlineGameMode NextGameMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PartnerUserId;
    
    ABRAMS_API FGameOnlineVisualLobbyNextGameMode();
};

