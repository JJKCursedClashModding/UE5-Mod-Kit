#pragma once
#include "CoreMinimal.h"
#include "ObjectPoolManager.h"
#include "GameObjectPoolManager.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameObjectPoolManager : public UObjectPoolManager {
    GENERATED_BODY()
public:
    UGameObjectPoolManager();

};

