#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterAttackVoiceType.h"
#include "GameAnimNotify.h"
#include "GameAnimNotify_PlayActionVoice.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_PlayActionVoice : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterAttackVoiceType AttackVoiceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FixedVoicePatternIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSituationAttackVoiceCheckEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForcePlayEnabled;
    
    UGameAnimNotify_PlayActionVoice();

};

