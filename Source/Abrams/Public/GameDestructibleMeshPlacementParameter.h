#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameDestructibleMeshPlacementParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameDestructibleMeshPlacementParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector MeshIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AdditionalOffset;
    
    FGameDestructibleMeshPlacementParameter();
};

