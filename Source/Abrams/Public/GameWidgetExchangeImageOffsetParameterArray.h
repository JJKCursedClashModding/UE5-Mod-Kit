#pragma once
#include "CoreMinimal.h"
#include "GameWidgetExchangeImageOffsetParameter.h"
#include "GameWidgetExchangeImageOffsetParameterArray.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetExchangeImageOffsetParameterArray {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameWidgetExchangeImageOffsetParameter> Array;
    
public:
    FGameWidgetExchangeImageOffsetParameterArray();
};

