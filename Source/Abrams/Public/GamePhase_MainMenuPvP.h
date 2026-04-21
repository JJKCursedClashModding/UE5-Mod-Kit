#pragma once
#include "CoreMinimal.h"
#include "GamePhase_MainMenuBase.h"
#include "GamePhase_MainMenuPvP.generated.h"

class AGameCharacterCaptureActor;

UCLASS(Blueprintable)
class ABRAMS_API UGamePhase_MainMenuPvP : public UGamePhase_MainMenuBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameCharacterCaptureActor* SituationOverviewCaptureActor;
    
public:
    UGamePhase_MainMenuPvP();

};

