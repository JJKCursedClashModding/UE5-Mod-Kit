#pragma once
#include "CoreMinimal.h"
#include "GameAnimNS.h"
#include "GameAnimationRenderWeightParameter.h"
#include "GameAnimNS_RadialBlur.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ABRAMS_API UGameAnimNS_RadialBlur : public UGameAnimNS {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameAnimationRenderWeightParameter WeightParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Dist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CenterPositionX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CenterPositionY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Density;
    
    UGameAnimNS_RadialBlur();

};

