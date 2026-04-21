#pragma once
#include "CoreMinimal.h"
#include "GameUserPvEEquipmentInfo.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameUserPvEEquipmentInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ItemIdArray;
    
    FGameUserPvEEquipmentInfo();
};

