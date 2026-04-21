#pragma once
#include "CoreMinimal.h"
#include "EGameBattleDrawType.h"
#include "EGameBattleMode.h"
#include "EGameBattlePair.h"
#include "GameBattleSettings.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameBattleSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BattleLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameBattleMode BattleMode;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameBattlePair BattlePair;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameBattleDrawType BattleDrawType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BgmId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTimeLimitInfinity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseMenuEnabled;
    
    FGameBattleSettings();
};

