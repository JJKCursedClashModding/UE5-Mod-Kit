#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameActionCameraRotationSpeed.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameActionCameraRotationSpeed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator StartSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator EndSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
    FGameActionCameraRotationSpeed();
};

