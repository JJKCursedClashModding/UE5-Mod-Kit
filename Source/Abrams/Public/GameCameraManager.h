#pragma once
#include "CoreMinimal.h"
#include "CameraManager.h"
#include "GameCameraManager.generated.h"

class AGameActionCamera;
class AGameDebugCamera;
class UGameCameraMode;

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API AGameCameraManager : public ACameraManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameCameraMode*> ModeArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCameraMode* ActiveMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameActionCamera* ActionCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameDebugCamera* DebugCamera;
    
public:
    AGameCameraManager(const FObjectInitializer& ObjectInitializer);

};

