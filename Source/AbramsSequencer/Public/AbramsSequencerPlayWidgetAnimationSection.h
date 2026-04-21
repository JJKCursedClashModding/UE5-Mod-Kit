#pragma once
#include "CoreMinimal.h"
#include "WidgetAnimationParameter.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerPlayWidgetAnimationSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerPlayWidgetAnimationSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWidgetAnimationParameter PlayAnimationParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UAbramsSequencerPlayWidgetAnimationSection();

};

