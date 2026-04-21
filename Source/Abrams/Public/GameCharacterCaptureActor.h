#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "Templates/SubclassOf.h"
#include "GameCharacterCaptureActor.generated.h"

class AGameCharacter;
class AGameCharacterCapturePanelActor;
class AGameSceneCapture2D;
class AGameShikigami;

UCLASS(Blueprintable)
class ABRAMS_API AGameCharacterCaptureActor : public AGameActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGameSceneCapture2D> SpawnSceneCaptureBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGameSceneCapture2D*> SceneCaptureArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGameCharacter*> SpawnedCharacterArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGameShikigami*> SpawnedShikigamiArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGameCharacterCapturePanelActor*> SpawnedPanelActorArray;
    
public:
    AGameCharacterCaptureActor(const FObjectInitializer& ObjectInitializer);

};

