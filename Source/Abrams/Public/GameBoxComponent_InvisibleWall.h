#pragma once
#include "CoreMinimal.h"
#include "GameBoxComponent.h"
#include "GameBoxComponent_InvisibleWall.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameBoxComponent_InvisibleWall : public UGameBoxComponent {
    GENERATED_BODY()
public:
    UGameBoxComponent_InvisibleWall(const FObjectInitializer& ObjectInitializer);

};

