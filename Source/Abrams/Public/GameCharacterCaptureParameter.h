#pragma once
#include "CoreMinimal.h"
#include "GameBattleCharacterSettings.h"
#include "GameCharacterCaptureParameter.generated.h"

USTRUCT(BlueprintType)
struct FGameCharacterCaptureParameter : public FGameBattleCharacterSettings {
    GENERATED_BODY()
public:
    ABRAMS_API FGameCharacterCaptureParameter();
};

