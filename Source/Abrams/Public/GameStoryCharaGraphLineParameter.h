#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStoryCharaGraphLineParameter.generated.h"

USTRUCT(BlueprintType)
struct FGameStoryCharaGraphLineParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WidthRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    ABRAMS_API FGameStoryCharaGraphLineParameter();
};

