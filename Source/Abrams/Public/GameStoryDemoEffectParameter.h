#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStoryDemoEffectParameter.generated.h"

USTRUCT(BlueprintType)
struct FGameStoryDemoEffectParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor LineColor;
    
    ABRAMS_API FGameStoryDemoEffectParameter();
};

