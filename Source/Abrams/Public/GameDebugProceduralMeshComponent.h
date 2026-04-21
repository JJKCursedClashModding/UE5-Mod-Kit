#pragma once
#include "CoreMinimal.h"
#include "DebugProceduralMeshComponent.h"
#include "GameDebugProceduralMeshComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameDebugProceduralMeshComponent : public UDebugProceduralMeshComponent {
    GENERATED_BODY()
public:
    UGameDebugProceduralMeshComponent(const FObjectInitializer& ObjectInitializer);

};

