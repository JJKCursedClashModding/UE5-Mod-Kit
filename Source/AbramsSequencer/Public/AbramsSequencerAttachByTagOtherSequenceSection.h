#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerAttachByTagOtherSequenceSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerAttachByTagOtherSequenceSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UAbramsSequencerAttachByTagOtherSequenceSection();

};

