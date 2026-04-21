#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerActorType.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerAttachByClassSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerAttachByClassSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerActorType ClassType;
    
    UAbramsSequencerAttachByClassSection();

};

