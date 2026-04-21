#pragma once
#include "CoreMinimal.h"
#include "GameWidgetRankPointClassParameter.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetRankPointClassParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ClassIconTexture;
    
    FGameWidgetRankPointClassParameter();
};

