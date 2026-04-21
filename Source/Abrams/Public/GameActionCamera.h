#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameActionCamera.generated.h"

class AActor;
class UCameraComponent;
class USpringArmComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameActionCamera : public AGameActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpringArmComponent* SpringArmComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* CameraComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* PrevViewerTarget;
    
public:
    AGameActionCamera(const FObjectInitializer& ObjectInitializer);

};

