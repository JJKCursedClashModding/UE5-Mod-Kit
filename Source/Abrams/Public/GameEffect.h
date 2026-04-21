#pragma once
#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "PoolableInterface.h"
#include "GameActor.h"
#include "GameEffect.generated.h"

class AActor;
class UGameCollisionKeeper;
class UGameEffectMovementController;
class UNiagaraComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameEffect : public AGameActor, public IPoolableInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraComponent*> NiagaraComponentArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameEffectMovementController* EffectMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* AttackCollisionKeeper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* DamageCollisionKeeper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* NullifiesDamageCollisionKeeper;
    
public:
    AGameEffect(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnComponentBeginOverlapEffect(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    

    // Fix for true pure virtual functions not being implemented
};

