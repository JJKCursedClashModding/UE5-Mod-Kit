#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputDataInterface.h"
#include "GameInputData.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameInputData : public UObject, public IInputDataInterface {
    GENERATED_BODY()
public:
    UGameInputData();


    // Fix for true pure virtual functions not being implemented
};

