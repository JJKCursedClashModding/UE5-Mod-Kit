#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerStoryDemoShowMessageSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerStoryDemoShowMessageSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TextId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StyleId;
    
    UAbramsSequencerStoryDemoShowMessageSection();

};

