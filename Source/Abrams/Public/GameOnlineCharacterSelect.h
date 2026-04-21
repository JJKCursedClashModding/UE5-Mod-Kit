#pragma once
#include "CoreMinimal.h"
#include "GameBattleCharacterSettings.h"
#include "GameOnlineUserCommunicateInfo.h"
#include "GameOnlineUserCustomizeInfo.h"
#include "GameUserPvEEquipmentInfo.h"
#include "GameUserPvEGrowthInfo.h"
#include "GameOnlineCharacterSelect.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineCharacterSelect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameBattleCharacterSettings BattleCharacterSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserCustomizeInfo UserCustomizeInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserCommunicateInfo UserCommunicateInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameUserPvEGrowthInfo UserPvEGrowthInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameUserPvEEquipmentInfo UserPvEEquipmentInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MapId;
    
    ABRAMS_API FGameOnlineCharacterSelect();
};

