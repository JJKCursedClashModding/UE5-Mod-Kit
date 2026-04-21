#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBindingSoundBase.h"
#include "AbramsSequencerPlayLoopSe_3DSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlayLoopSe_3DSection : public UAbramsSequencerSectionBindingSoundBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSyncLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeOutTime;
    
    UAbramsSequencerPlayLoopSe_3DSection();

};

