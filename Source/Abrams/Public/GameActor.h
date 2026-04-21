#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/HitResult.h"
#include "CollidableInterface.h"
#include "TickableInterface.h"
#include "GameActorInterface.h"
#include "GameActor.generated.h"

class UPrimitiveComponent;

UCLASS(Abstract, Blueprintable)
class ABRAMS_API AGameActor : public AActor, public IGameActorInterface, public ITickableInterface, public ICollidableInterface {
    GENERATED_BODY()
public:
    AGameActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    

    // Fix for true pure virtual functions not being implemented
};

