#pragma once
#include "CoreMinimal.h"
#include "EInputKey.h"
#include "EGameInputKey.h"
#include "GameInputKeyBinding.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameInputKeyBinding {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EInputKey, EGameInputKey> Map;
    
    FGameInputKeyBinding();
};

