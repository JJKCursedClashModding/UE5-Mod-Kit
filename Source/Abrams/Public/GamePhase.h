#pragma once
#include "CoreMinimal.h"
#include "PhaseBase.h"
#include "GamePhase.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMS_API UGamePhase : public UPhaseBase {
    GENERATED_BODY()
public:
    UGamePhase();

};

