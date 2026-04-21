#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateBase.h"
#include "AbramsSequencerSetVoiceVolumeEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerSetVoiceVolumeEvaluate : public FAbramsSequencerEvaluateBase {
    GENERATED_BODY()
public:
    FAbramsSequencerSetVoiceVolumeEvaluate();
};

