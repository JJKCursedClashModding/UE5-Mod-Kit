#pragma once
#include "CoreMinimal.h"
#include "GameAnimNS.h"
#include "GameAnimationRenderWeightParameter.h"
#include "GameAnimNS_NegaPosition.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ABRAMS_API UGameAnimNS_NegaPosition : public UGameAnimNS {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameAnimationRenderWeightParameter WeightParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UGameAnimNS_NegaPosition();

};

