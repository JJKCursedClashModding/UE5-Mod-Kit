#pragma once
#include "CoreMinimal.h"
#include "EInputKey.h"
#include "EGameInputKey.h"
#include "GameKeyBinding.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameKeyBinding {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameInputKey, EInputKey> Map;
    
    FGameKeyBinding();
};

