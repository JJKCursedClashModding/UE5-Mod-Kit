#pragma once
#include "CoreMinimal.h"
#include "GameOnlineUserCustomizeChatInfo.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineUserCustomizeChatInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BattleChatArray;
    
    ABRAMS_API FGameOnlineUserCustomizeChatInfo();
};

