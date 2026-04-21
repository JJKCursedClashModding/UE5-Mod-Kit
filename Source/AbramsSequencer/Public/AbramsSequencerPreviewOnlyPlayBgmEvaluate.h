#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerEvaluateMasterSoundBase.h"
#include "AbramsSequencerPreviewOnlyPlayBgmEvaluate.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSSEQUENCER_API FAbramsSequencerPreviewOnlyPlayBgmEvaluate : public FAbramsSequencerEvaluateMasterSoundBase {
    GENERATED_BODY()
public:
    FAbramsSequencerPreviewOnlyPlayBgmEvaluate();
};

