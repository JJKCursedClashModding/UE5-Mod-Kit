#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSectionUMGBindingBase.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSectionUMGBindingBase : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceUpdateTargetWidgetCache;
    
    UAbramsSequencerSectionUMGBindingBase();

};

