#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerAttachByTagSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerAttachByTagSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    UAbramsSequencerAttachByTagSection();

};

