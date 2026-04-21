#pragma once
#include "CoreMinimal.h"
#include "EGameOnlinePvEIntervalStatus.h"
#include "GameOnlinePvEIntervalAction.h"
#include "GameOnlinePvEIntervalStatus.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlinePvEIntervalStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlinePvEIntervalAction PartnerAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlinePvEIntervalStatus Status;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PvEMissionId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BattleLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> MissionWaveIdArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> MissionTaskIdArray;
    
    ABRAMS_API FGameOnlinePvEIntervalStatus();
};

