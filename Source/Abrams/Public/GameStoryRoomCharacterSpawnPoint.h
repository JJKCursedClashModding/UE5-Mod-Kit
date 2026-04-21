#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameStoryRoomCharacterSpawnPoint.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameStoryRoomCharacterSpawnPoint : public AGameActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
public:
    AGameStoryRoomCharacterSpawnPoint(const FObjectInitializer& ObjectInitializer);

};

