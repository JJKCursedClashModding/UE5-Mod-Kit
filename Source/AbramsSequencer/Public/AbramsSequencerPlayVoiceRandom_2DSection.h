#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionMasterSoundBase.h"
#include "AbramsSequencerPlayVoiceRandom_2DSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlayVoiceRandom_2DSection : public UAbramsSequencerSectionMasterSoundBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetCharacterTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AllyGroupVoiceSetId;
    
    UAbramsSequencerPlayVoiceRandom_2DSection();

};

