#pragma once
#include "CoreMinimal.h"
#include "SaveDataManager.h"
#include "GameSaveDataManager.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameSaveDataManager : public USaveDataManager {
    GENERATED_BODY()
public:
    UGameSaveDataManager();

};

