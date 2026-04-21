#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionMasterSoundBase.h"
#include "AbramsSequencerPlayLoopSe_2DSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlayLoopSe_2DSection : public UAbramsSequencerSectionMasterSoundBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeOutTime;
    
    UAbramsSequencerPlayLoopSe_2DSection();

};

