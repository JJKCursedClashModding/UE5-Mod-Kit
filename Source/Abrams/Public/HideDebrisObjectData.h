#pragma once
#include "CoreMinimal.h"
#include "EGameDebrisObjectHideCondition.h"
#include "HideDebrisObjectData.generated.h"

class AGameDestructibleObject;

USTRUCT(BlueprintType)
struct FHideDebrisObjectData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameDestructibleObject* HideObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameDebrisObjectHideCondition HideCondition;
    
    ABRAMS_API FHideDebrisObjectData();
};

