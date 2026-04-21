#pragma once
#include "CoreMinimal.h"
#include "GameUserPvEEquipmentInfo.h"
#include "GameUserPvEGrowthInfo.h"
#include "GameOnlinePvESettings.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlinePvESettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameUserPvEEquipmentInfo> EquipmentInfoArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameUserPvEGrowthInfo> GrowthInfoArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> RiskValueArray;
    
    ABRAMS_API FGameOnlinePvESettings();
};

