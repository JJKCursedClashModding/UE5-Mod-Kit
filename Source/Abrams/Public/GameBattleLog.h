#pragma once
#include "CoreMinimal.h"
#include "EGameBattleResultType.h"
#include "EGameCharacterIndex.h"
#include "EGameOnlineGameMode.h"
#include "GameBattleCharacterLog.h"
#include "GameBattleSettings.h"
#include "GameBattleLog.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameBattleLog {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> RandomStreamSeedArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlineGameMode OnlineGameMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterIndex PlayableCharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameBattleResultType BattleResultType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameBattleSettings BattleSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameBattleCharacterLog> CharacterLogArray;
    
    FGameBattleLog();
};

