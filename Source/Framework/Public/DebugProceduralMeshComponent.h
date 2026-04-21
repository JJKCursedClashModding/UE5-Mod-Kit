#pragma once
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "DebugProceduralMeshComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FRAMEWORK_API UDebugProceduralMeshComponent : public UProceduralMeshComponent {
    GENERATED_BODY()
public:
    UDebugProceduralMeshComponent(const FObjectInitializer& ObjectInitializer);

};

