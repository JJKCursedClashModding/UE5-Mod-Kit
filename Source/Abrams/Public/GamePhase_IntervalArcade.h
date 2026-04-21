#pragma once
#include "CoreMinimal.h"
#include "GamePhase.h"
#include "GamePhase_IntervalArcade.generated.h"

class AGameCharacterCaptureActor;

UCLASS(Blueprintable)
class ABRAMS_API UGamePhase_IntervalArcade : public UGamePhase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameCharacterCaptureActor* SituationOverviewCaptureActor;
    
public:
    UGamePhase_IntervalArcade();

};

