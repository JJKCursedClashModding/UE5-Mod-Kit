#pragma once
#include "CoreMinimal.h"
#include "GameBattleBuffDebuffIconParameter.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FGameBattleBuffDebuffIconParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* Texture;
    
    ABRAMS_API FGameBattleBuffDebuffIconParameter();
};

