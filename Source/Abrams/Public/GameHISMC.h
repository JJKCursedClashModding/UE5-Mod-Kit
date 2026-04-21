#pragma once
#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "GameHISMC.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameHISMC : public UHierarchicalInstancedStaticMeshComponent {
    GENERATED_BODY()
public:
    UGameHISMC(const FObjectInitializer& ObjectInitializer);

};

