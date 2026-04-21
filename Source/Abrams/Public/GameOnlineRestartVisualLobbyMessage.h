#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineRestartVisualLobbyType.h"
#include "GameOnlineRestartVisualLobbyMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineRestartVisualLobbyMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlineRestartVisualLobbyType RestartType;
    
    ABRAMS_API FGameOnlineRestartVisualLobbyMessage();
};

