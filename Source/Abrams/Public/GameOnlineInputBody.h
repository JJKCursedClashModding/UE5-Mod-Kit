#pragma once
#include "CoreMinimal.h"
#include "GameOnlineInputData.h"
#include "GameOnlineInputBody.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineInputBody {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineInputData InputDataArray[4];
    
    ABRAMS_API FGameOnlineInputBody();
};

