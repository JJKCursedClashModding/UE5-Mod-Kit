#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionMasterSoundBase.h"
#include "AbramsSequencerPlayVoice_2DSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlayVoice_2DSection : public UAbramsSequencerSectionMasterSoundBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowSubtitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverrideSubTitleTextId;
    
    UAbramsSequencerPlayVoice_2DSection();

};

