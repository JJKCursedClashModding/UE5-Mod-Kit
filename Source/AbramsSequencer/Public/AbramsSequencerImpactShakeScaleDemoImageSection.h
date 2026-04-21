#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerImpactShakeScaleDemoImageSection.generated.h"

class UGameCurveStoryDemoShake;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerImpactShakeScaleDemoImageSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCurveStoryDemoShake* ShakeObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinScale;
    
    UAbramsSequencerImpactShakeScaleDemoImageSection();

};

