#pragma once
#include "CoreMinimal.h"
#include "GameCommonChatListItemData.generated.h"

class UGameChatListItemData;

USTRUCT(BlueprintType)
struct FGameCommonChatListItemData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameChatListItemData*> ChatItemDataList;
    
    ABRAMS_API FGameCommonChatListItemData();
};

