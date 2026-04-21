#pragma once
#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "CameraManager.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class FRAMEWORK_API ACameraManager : public APlayerCameraManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CameraViewTarget;
    
public:
    ACameraManager(const FObjectInitializer& ObjectInitializer);

};

