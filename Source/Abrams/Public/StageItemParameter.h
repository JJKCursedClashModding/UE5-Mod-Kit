#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StageItemParameter.generated.h"

USTRUCT(BlueprintType)
struct FStageItemParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Size;
    
    ABRAMS_API FStageItemParameter();
};

