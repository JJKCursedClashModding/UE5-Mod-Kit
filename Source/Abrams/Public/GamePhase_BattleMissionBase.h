#pragma once
#include "CoreMinimal.h"
#include "GamePhase_BattleBase.h"
#include "GamePhase_BattleMissionBase.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMS_API UGamePhase_BattleMissionBase : public UGamePhase_BattleBase {
    GENERATED_BODY()
public:
    UGamePhase_BattleMissionBase();

};

