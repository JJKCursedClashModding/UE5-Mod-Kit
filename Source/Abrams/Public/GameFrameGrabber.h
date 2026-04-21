#pragma once
#include "CoreMinimal.h"
#include "GameCaptureActor.h"
#include "GameFrameGrabber.generated.h"

class UGameFrameGrabberCaptureData;

UCLASS(Blueprintable)
class ABRAMS_API AGameFrameGrabber : public AGameCaptureActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameFrameGrabberCaptureData*> CaptureDataList;
    
public:
    AGameFrameGrabber(const FObjectInitializer& ObjectInitializer);

};

