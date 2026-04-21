#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetExchangeImageType.h"
#include "GameWidgetExchangeImageOffsetParameterArray.h"
#include "GameWidgetParameterBase.h"
#include "GameWidgetExchangeImageParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetExchangeImageParameter : public UGameWidgetParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetExchangeImageType, FGameWidgetExchangeImageOffsetParameterArray> ImageOffsetParameterMap;
    
public:
    UGameWidgetExchangeImageParameter();

};

