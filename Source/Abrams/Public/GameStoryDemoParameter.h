#pragma once
#include "CoreMinimal.h"
#include "GameStoryDemoFadeOutParameter.h"
#include "GameStoryDemoParameter.generated.h"

USTRUCT(BlueprintType)
struct FGameStoryDemoParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameStoryDemoFadeOutParameter ShakeFadeOutParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameStoryDemoFadeOutParameter LineEffectFadeOutParameter;
    
    ABRAMS_API FGameStoryDemoParameter();
};

