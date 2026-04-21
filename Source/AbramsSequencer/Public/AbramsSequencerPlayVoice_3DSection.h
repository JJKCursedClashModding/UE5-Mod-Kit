#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBindingSoundBase.h"
#include "AbramsSequencerPlayVoice_3DSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlayVoice_3DSection : public UAbramsSequencerSectionBindingSoundBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowSubtitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSyncLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverrideSubTitleTextId;
    
    UAbramsSequencerPlayVoice_3DSection();

};

