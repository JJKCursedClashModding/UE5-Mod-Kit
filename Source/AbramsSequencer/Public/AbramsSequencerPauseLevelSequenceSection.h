#pragma once
#include "CoreMinimal.h"
#include "EGamePauseFlag.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerPauseLevelSequenceSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPauseLevelSequenceSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGamePauseFlag PauseType;
    
    UAbramsSequencerPauseLevelSequenceSection();

};

