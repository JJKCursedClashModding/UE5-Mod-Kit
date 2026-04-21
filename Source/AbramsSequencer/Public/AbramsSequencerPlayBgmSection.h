#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionMasterSoundBase.h"
#include "AbramsSequencerPlayBgmSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlayBgmSection : public UAbramsSequencerSectionMasterSoundBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoopEnabled;
    
    UAbramsSequencerPlayBgmSection();

};

