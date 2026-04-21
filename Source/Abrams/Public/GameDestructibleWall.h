#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameDestructibleWall.generated.h"

class UGameBoxComponent_InvisibleWall;
class UGameDestructibleReactioner;

UCLASS(Blueprintable)
class ABRAMS_API AGameDestructibleWall : public AGameActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBoxComponent_InvisibleWall* BoxComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameDestructibleReactioner* Reactioner;
    
public:
    AGameDestructibleWall(const FObjectInitializer& ObjectInitializer);

};

