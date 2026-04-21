#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameDestructibleDecal.generated.h"

class UGameBoxComponent;
class UGameDestructibleReactioner;

UCLASS(Blueprintable)
class ABRAMS_API AGameDestructibleDecal : public AGameActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBoxComponent* BoxComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameDestructibleReactioner* Reactioner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Defence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActionCameraObstacle;
    
public:
    AGameDestructibleDecal(const FObjectInitializer& ObjectInitializer);

};

