#pragma once
#include "CoreMinimal.h"
#include "EGameFootstepActionType.h"
#include "EGameCharacterFoot.h"
#include "GameAnimNotify.h"
#include "GameSoundPlayParameter.h"
#include "GameAnimNotify_Footstep.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_Footstep : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterFoot Foot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameFootstepActionType FootstepActionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameSoundPlayParameter PlayParameter;
    
    UGameAnimNotify_Footstep();

};

