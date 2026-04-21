#pragma once
#include "CoreMinimal.h"
#include "KeyRepeatParameter.generated.h"

USTRUCT(BlueprintType)
struct FRAMEWORK_API FKeyRepeatParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FirstRepeatTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AfterSecondRepeatTime;
    
    FKeyRepeatParameter();
};

