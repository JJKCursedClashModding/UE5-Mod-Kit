#pragma once
#include "CoreMinimal.h"
#include "GameSoundPlayParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameSoundPlayParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PitchOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AttenuationDistanceStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AttenuationDistanceLength;
    
    FGameSoundPlayParameter();
};

