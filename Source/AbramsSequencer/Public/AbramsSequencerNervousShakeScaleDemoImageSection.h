#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerNervousShakeScaleDemoImageSection.generated.h"

class UGameCurveStoryDemoShake;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerNervousShakeScaleDemoImageSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCurveStoryDemoShake* ShakeObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinScale;
    
    UAbramsSequencerNervousShakeScaleDemoImageSection();

};

