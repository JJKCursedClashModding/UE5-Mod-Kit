#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterIndex.h"
#include "GameBattleLogDebugCharacterDataArray.h"
#include "GameBattleDebugLog.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameBattleDebugLog {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameCharacterIndex, FGameBattleLogDebugCharacterDataArray> CharacterDataMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameCharacterIndex, int32> FrameNumberMap;
    
    FGameBattleDebugLog();
};

