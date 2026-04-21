#pragma once
#include "CoreMinimal.h"
#include "GameOnlineUserCustomizeChatInfo.h"
#include "GameOnlineUserCustomizeVoiceInfo.h"
#include "GameOnlineUserCustomizeInfo.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineUserCustomizeInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserCustomizeChatInfo UserCustomizeChatInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineUserCustomizeVoiceInfo UserCustomizeVoiceInfo;
    
    ABRAMS_API FGameOnlineUserCustomizeInfo();
};

