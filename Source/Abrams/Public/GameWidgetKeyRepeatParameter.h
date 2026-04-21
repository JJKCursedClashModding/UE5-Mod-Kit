#pragma once
#include "CoreMinimal.h"
#include "KeyRepeatParameter.h"
#include "EGameInputKey.h"
#include "GameWidgetParameterBase.h"
#include "GameWidgetKeyRepeatParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetKeyRepeatParameter : public UGameWidgetParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameInputKey, FKeyRepeatParameter> KeyRepeatParameterMap;
    
public:
    UGameWidgetKeyRepeatParameter();

};

