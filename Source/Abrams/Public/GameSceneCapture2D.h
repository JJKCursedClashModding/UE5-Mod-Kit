#pragma once
#include "CoreMinimal.h"
#include "GameCaptureActor.h"
#include "GameSceneCapture2D.generated.h"

class UGameSceneCaptureParameter;
class UGameTextureRenderTarget2D;
class USceneCaptureComponent2D;

UCLASS(Blueprintable)
class ABRAMS_API AGameSceneCapture2D : public AGameCaptureActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneCaptureComponent2D* CaptureComponent2D;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameTextureRenderTarget2D* RenderTarget2D;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameSceneCaptureParameter* CurrentCaptureParameter;
    
public:
    AGameSceneCapture2D(const FObjectInitializer& ObjectInitializer);

};

