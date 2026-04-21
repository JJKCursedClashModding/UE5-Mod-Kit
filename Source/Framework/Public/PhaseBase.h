#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PhaseBase.generated.h"

UCLASS(Abstract, Blueprintable)
class FRAMEWORK_API UPhaseBase : public UObject {
    GENERATED_BODY()
public:
    UPhaseBase();

};

