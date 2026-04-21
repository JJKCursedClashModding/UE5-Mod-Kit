#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineGameMode.h"
#include "GameVisualLobbyMatchRuleSettings.h"
#include "GameOnlineVisualLobbySettings.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineVisualLobbySettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameVisualLobbyMatchRuleSettings RuleSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlineGameMode SettingGameMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ABRAMS_API FGameOnlineVisualLobbySettings();
};

