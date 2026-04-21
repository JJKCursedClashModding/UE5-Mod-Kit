#pragma once
#include "CoreMinimal.h"
#include "PhaseManager.h"
#include "TickableInterface.h"
#include "GamePhaseManager.generated.h"

class UGamePhase;

UCLASS(Blueprintable)
class ABRAMS_API AGamePhaseManager : public APhaseManager, public ITickableInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGamePhase* ActiveGamePhase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGamePhase* NextGamePhase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGamePhase* PrevGamePhase;
    
public:
    AGamePhaseManager(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

