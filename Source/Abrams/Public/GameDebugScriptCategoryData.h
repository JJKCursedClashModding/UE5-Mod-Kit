#pragma once
#include "CoreMinimal.h"
#include "GameDebugScriptCategoryData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FGameDebugScriptCategoryData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> ListItemList;
    
    ABRAMS_API FGameDebugScriptCategoryData();
};

