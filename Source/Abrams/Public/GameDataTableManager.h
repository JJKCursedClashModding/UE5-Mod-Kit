#pragma once
#include "CoreMinimal.h"
#include "DataTableManager.h"
#include "GameDataTableManager.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API AGameDataTableManager : public ADataTableManager {
    GENERATED_BODY()
public:
    AGameDataTableManager(const FObjectInitializer& ObjectInitializer);

};

