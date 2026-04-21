#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBindingSoundBase.h"
#include "AbramsSequencerPlayVoiceRandom_3DSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlayVoiceRandom_3DSection : public UAbramsSequencerSectionBindingSoundBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSyncLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AllyGroupVoiceSetId;
    
    UAbramsSequencerPlayVoiceRandom_3DSection();

};

