#pragma once
#include "CoreMinimal.h"
#include "PoolableInterface.h"
#include "GameActor.h"
#include "GameTrap.generated.h"

class UGameCollisionKeeper;
class UGameTrapActionController;
class UGameTrapMaterialController;
class UMeshComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameTrap : public AGameActor, public IPoolableInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameTrapActionController* ActionController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameTrapMaterialController* MaterialController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* AttackCollisionKeeper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* DamageCollisionKeeper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionKeeper* NullifiesDamageCollisionKeeper;
    
public:
    AGameTrap(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

