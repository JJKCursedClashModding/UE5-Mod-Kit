#pragma once
#include "CoreMinimal.h"
#include "GameAnimNotify.h"
#include "GameAnimNotify_LookAtTargetYaw.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_LookAtTargetYaw : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreHomingInvalidate;
    
    UGameAnimNotify_LookAtTargetYaw();

};

