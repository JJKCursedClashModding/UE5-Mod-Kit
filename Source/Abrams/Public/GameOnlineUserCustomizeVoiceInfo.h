#pragma once
#include "CoreMinimal.h"
#include "GameOnlineUserCustomizeVoiceInfo.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineUserCustomizeVoiceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NormalAttackVoiceIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CursedEnergyAttackVoiceIndex;
    
    ABRAMS_API FGameOnlineUserCustomizeVoiceInfo();
};

