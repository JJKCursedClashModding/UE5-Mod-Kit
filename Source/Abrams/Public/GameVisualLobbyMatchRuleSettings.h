#pragma once
#include "CoreMinimal.h"
#include "EGameBattleDrawType.h"
#include "GameVisualLobbyMatchCharacterInfo.h"
#include "GameVisualLobbyMatchRuleSettings.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameVisualLobbyMatchRuleSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameVisualLobbyMatchCharacterInfo> CharacterInfoList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameBattleDrawType BattleDrawType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseMenuEnabled;
    
    FGameVisualLobbyMatchRuleSettings();
};

