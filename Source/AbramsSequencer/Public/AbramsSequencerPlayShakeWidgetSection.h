#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerPlayShakeWidgetSection.generated.h"

class UGameCurveStoryDemoShake;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlayShakeWidgetSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCurveStoryDemoShake* ShakeObject;
    
    UAbramsSequencerPlayShakeWidgetSection();

};

