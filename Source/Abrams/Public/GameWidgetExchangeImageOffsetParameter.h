#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameWidgetExchangeImageOffsetParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetExchangeImageOffsetParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Offset;
    
    FGameWidgetExchangeImageOffsetParameter();
};

