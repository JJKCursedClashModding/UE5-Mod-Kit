#pragma once
#include "CoreMinimal.h"
#include "GameActionCameraFOVSpeed.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameActionCameraFOVSpeed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
    FGameActionCameraFOVSpeed();
};

