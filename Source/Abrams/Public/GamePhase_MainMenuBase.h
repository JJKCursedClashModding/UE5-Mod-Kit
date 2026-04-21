#pragma once
#include "CoreMinimal.h"
#include "GamePhase.h"
#include "GamePhase_MainMenuBase.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMS_API UGamePhase_MainMenuBase : public UGamePhase {
    GENERATED_BODY()
public:
    UGamePhase_MainMenuBase();

};

