#pragma once
#include "CoreMinimal.h"
#include "GameBattleLogDebugCharacterData.h"
#include "GameBattleLogDebugCharacterDataArray.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameBattleLogDebugCharacterDataArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameBattleLogDebugCharacterData> DataArray;
    
    FGameBattleLogDebugCharacterDataArray();
};

