#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameAnimNS.h"
#include "GameAnimNS_LookAtTargetPitch.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ABRAMS_API UGameAnimNS_LookAtTargetPitch : public UGameAnimNS {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector OffsetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LimitAngleLower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LimitAngleUpper;
    
    UGameAnimNS_LookAtTargetPitch();

};

