#pragma once
#include "CoreMinimal.h"
#include "GameCommonStampListItemData.generated.h"

class UGameStampListItemData;

USTRUCT(BlueprintType)
struct FGameCommonStampListItemData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameStampListItemData*> StampItemDataList;
    
    ABRAMS_API FGameCommonStampListItemData();
};

