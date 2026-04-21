#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameAnimNotify.h"
#include "GameAnimNotify_PlayAttackBeginEffect.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_PlayAttackBeginEffect : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOtherAttackBeginEffectPlayingDisabled;
    
    UGameAnimNotify_PlayAttackBeginEffect();

};

