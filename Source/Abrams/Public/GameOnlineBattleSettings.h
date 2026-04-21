#pragma once
#include "CoreMinimal.h"
#include "GameBattleSettings.h"
#include "GameOnlineCreateSessionSettings.h"
#include "GameOnlinePvESettings.h"
#include "GameOnlineUserBattleSettings.h"
#include "GameOnlineVisualLobbySettings.h"
#include "GameOnlineBattleSettings.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineBattleSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameOnlineUserBattleSettings> OnlineUserBattleSettingsArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameBattleSettings BattleSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlinePvESettings PvESettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineVisualLobbySettings VisualLobbySettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineCreateSessionSettings SessionSettings;
    
    ABRAMS_API FGameOnlineBattleSettings();
};

