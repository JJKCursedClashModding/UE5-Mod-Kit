#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionMasterWidgetBase.h"
#include "AbramsSequencerLoopSectionSettingsSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerLoopSectionSettingsSection : public UAbramsSequencerSectionMasterWidgetBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LoopCount;
    
    UAbramsSequencerLoopSectionSettingsSection();

};

