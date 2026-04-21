#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterIndex.h"
#include "GameBattleCharacterSettings.h"
#include "GameOnlineInputSettings.h"
#include "GameOnlineUserCommunicateInfo.h"
#include "GameOnlineUserCustomizeInfo.h"
#include "GameOnlineUserInfo.h"
#include "GameOnlineUserBattleSettings.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineUserBattleSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineInputSettings InputSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameBattleCharacterSettings BattleCharacterSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserCustomizeInfo UserCustomizeInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserCommunicateInfo UserCommunicateInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserInfo UserInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterIndex CharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AILevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAI;
    
    ABRAMS_API FGameOnlineUserBattleSettings();
};

