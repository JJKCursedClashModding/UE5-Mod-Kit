#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameStoryRoomCamera.generated.h"

class UCameraComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameStoryRoomCamera : public AGameActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* CameraComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
public:
    AGameStoryRoomCamera(const FObjectInitializer& ObjectInitializer);

};

