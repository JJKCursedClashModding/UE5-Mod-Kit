#pragma once
#include "CoreMinimal.h"
#include "GameWidgetItemCategoryParameter.generated.h"

class UPaperSprite;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetItemCategoryParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPaperSprite* ItemCategorySprite;
    
    FGameWidgetItemCategoryParameter();
};

