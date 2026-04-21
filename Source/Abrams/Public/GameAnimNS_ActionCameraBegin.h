#pragma once
#include "CoreMinimal.h"
#include "EGameActionCameraPriority.h"
#include "GameActionCameraOption.h"
#include "GameActionCameraParameter.h"
#include "GameAnimNS.h"
#include "GameAnimNS_ActionCameraBegin.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ABRAMS_API UGameAnimNS_ActionCameraBegin : public UGameAnimNS {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameActionCameraPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameActionCameraParameter ActionCameraParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameActionCameraOption ActionCameraOption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameActionCameraParameter> SubActionCameraParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayableCharacterOnly;
    
    UGameAnimNS_ActionCameraBegin();

};

