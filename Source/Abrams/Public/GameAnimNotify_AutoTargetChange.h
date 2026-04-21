#pragma once
#include "CoreMinimal.h"
#include "GameAnimNotify.h"
#include "GameAnimNotify_AutoTargetChange.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_AutoTargetChange : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDamageSendNeeded;
    
    UGameAnimNotify_AutoTargetChange();

};

