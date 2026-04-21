#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBindingSoundBase.h"
#include "AbramsSequencerPlaySe_3DSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlaySe_3DSection : public UAbramsSequencerSectionBindingSoundBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSyncLocation;
    
    UAbramsSequencerPlaySe_3DSection();

};

