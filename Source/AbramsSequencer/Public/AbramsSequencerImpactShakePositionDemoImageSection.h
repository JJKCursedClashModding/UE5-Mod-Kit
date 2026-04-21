#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerImpactShakePositionDemoImageSection.generated.h"

class UGameCurveStoryDemoShake;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerImpactShakePositionDemoImageSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCurveStoryDemoShake* ShakeObject;
    
    UAbramsSequencerImpactShakePositionDemoImageSection();

};

