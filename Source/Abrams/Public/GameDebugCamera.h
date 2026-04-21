#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameDebugCamera.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameDebugCamera : public AGameActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpringArmComponent* SpringArm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* Camera;
    
public:
    AGameDebugCamera(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DebugCameraDeactivate();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DebugCameraActivate();
    
};

