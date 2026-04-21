#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameFrameGrabberCaptureData.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class UGameFrameGrabberCaptureData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> CaptureFrameData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CaptureFrameTexture;
    
    UGameFrameGrabberCaptureData();

};

