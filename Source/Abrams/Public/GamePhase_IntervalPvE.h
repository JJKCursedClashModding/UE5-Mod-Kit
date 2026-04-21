#pragma once
#include "CoreMinimal.h"
#include "GamePhase.h"
#include "GamePhase_IntervalPvE.generated.h"

class AGameCharacterCaptureActor;

UCLASS(Blueprintable)
class ABRAMS_API UGamePhase_IntervalPvE : public UGamePhase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameCharacterCaptureActor* SituationOverviewCaptureActor;
    
public:
    UGamePhase_IntervalPvE();

};

