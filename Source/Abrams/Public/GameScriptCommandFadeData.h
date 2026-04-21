#pragma once
#include "CoreMinimal.h"
#include "EFadeColorType.h"
#include "GameScriptCommandFadeData.generated.h"

USTRUCT(BlueprintType)
struct FGameScriptCommandFadeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFadeColorType FadeType;
    
    ABRAMS_API FGameScriptCommandFadeData();
};

