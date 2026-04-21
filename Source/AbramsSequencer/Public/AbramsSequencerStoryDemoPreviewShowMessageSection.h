#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionMasterBase.h"
#include "AbramsSequencerStoryDemoPreviewShowMessageSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerStoryDemoPreviewShowMessageSection : public UAbramsSequencerSectionMasterBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TextId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TextTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VoiceTime;
    
    UAbramsSequencerStoryDemoPreviewShowMessageSection();

};

