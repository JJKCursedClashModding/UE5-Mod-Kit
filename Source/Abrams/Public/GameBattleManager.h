#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TickableInterface.h"
#include "GameBattleManager.generated.h"

class AGameBattleArea;

UCLASS(Blueprintable)
class ABRAMS_API AGameBattleManager : public AActor, public ITickableInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameBattleArea* BattleArea;
    
public:
    AGameBattleManager(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

