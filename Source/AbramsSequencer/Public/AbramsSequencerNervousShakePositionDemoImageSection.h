#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerNervousShakePositionDemoImageSection.generated.h"

class UGameCurveStoryDemoShake;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerNervousShakePositionDemoImageSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCurveStoryDemoShake* ShakeObject;
    
    UAbramsSequencerNervousShakePositionDemoImageSection();

};

