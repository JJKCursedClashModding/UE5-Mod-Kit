#pragma once
#include "CoreMinimal.h"
#include "EGameBattleTeam.h"
#include "GameBattleCharacterSettings.h"
#include "GameInputLogArray.h"
#include "GameInputSettings.h"
#include "GameBattleCharacterLog.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameBattleCharacterLog {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RankPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameBattleTeam BattleTeam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameBattleCharacterSettings CharacterSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameInputSettings InputSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameInputLogArray InputLogArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NormalAttackVoiceIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CursedEnergyAttackVoiceIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpecialTagComboAssistEnabled;
    
    FGameBattleCharacterLog();
};

