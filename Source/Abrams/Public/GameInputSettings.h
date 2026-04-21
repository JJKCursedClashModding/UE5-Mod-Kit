#pragma once
#include "CoreMinimal.h"
#include "GameKeyBinding.h"
#include "GameKeyboardBinding.h"
#include "GameInputSettings.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameInputSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameKeyBinding KeyBinding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameKeyboardBinding KeyboardBinding;
    
    FGameInputSettings();
};

