#pragma once
#include "CoreMinimal.h"
#include "GamePhase.h"
#include "GamePhase_BattleBase.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMS_API UGamePhase_BattleBase : public UGamePhase {
    GENERATED_BODY()
public:
    UGamePhase_BattleBase();

};

