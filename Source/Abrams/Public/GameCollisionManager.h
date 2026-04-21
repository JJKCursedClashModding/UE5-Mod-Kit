#pragma once
#include "CoreMinimal.h"
#include "CollisionManager.h"
#include "TickableInterface.h"
#include "GameCollisionManager.generated.h"

class UGameCollisionModifier;

UCLASS(Blueprintable)
class ABRAMS_API AGameCollisionManager : public ACollisionManager, public ITickableInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCollisionModifier* CollisionModifier;
    
public:
    AGameCollisionManager(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

