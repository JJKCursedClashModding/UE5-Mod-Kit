#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameActionCameraLocationSpeed.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameActionCameraLocationSpeed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StartSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector EndSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
    FGameActionCameraLocationSpeed();
};

