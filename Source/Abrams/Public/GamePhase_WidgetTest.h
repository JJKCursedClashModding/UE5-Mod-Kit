#pragma once
#include "CoreMinimal.h"
#include "GamePhase.h"
#include "GamePhase_WidgetTest.generated.h"

class AGameCharacterCaptureActor;

UCLASS(Blueprintable)
class ABRAMS_API UGamePhase_WidgetTest : public UGamePhase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameCharacterCaptureActor* SituationOverviewCaptureActor;
    
public:
    UGamePhase_WidgetTest();

};

