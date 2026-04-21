#pragma once
#include "CoreMinimal.h"
#include "GameOnlineUserInfo.h"
#include "GameOnlineConnectedMessage.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineConnectedMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserInfo UserInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Password;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PartnerUserId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSolo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvite;
    
    ABRAMS_API FGameOnlineConnectedMessage();
};

