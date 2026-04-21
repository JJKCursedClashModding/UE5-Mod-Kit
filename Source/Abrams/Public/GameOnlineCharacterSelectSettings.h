#pragma once
#include "CoreMinimal.h"
#include "EGameBattlePair.h"
#include "EGameOnlineCharacterSelectStatus.h"
#include "GameOnlineCharacterSelectSettings.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineCharacterSelectSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlineCharacterSelectStatus Status;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameBattlePair BattlePair;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> IgnoreCharacterIds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPartnerCPU;
    
    ABRAMS_API FGameOnlineCharacterSelectSettings();
};

