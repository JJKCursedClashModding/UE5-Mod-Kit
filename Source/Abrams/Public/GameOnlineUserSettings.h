#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterIndex.h"
#include "GameOnlineUserCustomizePlayerCardInfo.h"
#include "GameOnlineUserInfo.h"
#include "GameOnlineUserSettings.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineUserSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserInfo UserInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserCustomizePlayerCardInfo PlayerCardInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterIndex CharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPvESOS;
    
    ABRAMS_API FGameOnlineUserSettings();
};

