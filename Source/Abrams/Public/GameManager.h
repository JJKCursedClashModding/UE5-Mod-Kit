#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

class AGameFrameGrabber;
class UGameSoundVoicePlayer;

UCLASS(Blueprintable)
class ABRAMS_API AGameManager : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameFrameGrabber* CaptureActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameSoundVoicePlayer* VoicePlayer;
    
public:
    AGameManager(const FObjectInitializer& ObjectInitializer);

};

