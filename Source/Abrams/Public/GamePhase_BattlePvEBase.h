#pragma once
#include "CoreMinimal.h"
#include "GamePhase_BattleMissionBase.h"
#include "GamePhase_BattlePvEBase.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMS_API UGamePhase_BattlePvEBase : public UGamePhase_BattleMissionBase {
    GENERATED_BODY()
public:
    UGamePhase_BattlePvEBase();

};

