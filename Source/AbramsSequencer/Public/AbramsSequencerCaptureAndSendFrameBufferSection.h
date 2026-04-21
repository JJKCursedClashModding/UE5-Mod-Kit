#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerSendFrameBufferTargetType.h"
#include "Engine/EngineTypes.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerCaptureAndSendFrameBufferSection.generated.h"

class UGameTextureRenderTarget2D;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerCaptureAndSendFrameBufferSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerSendFrameBufferTargetType SendTargetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESceneCaptureSource> CaptureSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, TEnumAsByte<ESceneCaptureSource>> MapOverrideCaptureSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaterialIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceSetAspectRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameTextureRenderTarget2D* TargetTexture;
    
    UAbramsSequencerCaptureAndSendFrameBufferSection();

};

