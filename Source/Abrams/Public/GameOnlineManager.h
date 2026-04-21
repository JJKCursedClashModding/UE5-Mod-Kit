#pragma once
#include "CoreMinimal.h"
#include "OnlineManager.h"
#include "GameOnlineManager.generated.h"

class AOnlineBeaconHost;
class UGameOnlineKpi;

UCLASS(Blueprintable)
class ABRAMS_API AGameOnlineManager : public AOnlineManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AOnlineBeaconHost* OnlineBeaconHost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameOnlineKpi* Kpi;
    
public:
    AGameOnlineManager(const FObjectInitializer& ObjectInitializer);

};

