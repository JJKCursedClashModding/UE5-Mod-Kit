#pragma once
#include "CoreMinimal.h"
#include "EGameInputKey.h"
#include "GameKeyboardList.h"
#include "GameKeyboardBinding.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameKeyboardBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameInputKey, FGameKeyboardList> Map;
    
    FGameKeyboardBinding();
};

