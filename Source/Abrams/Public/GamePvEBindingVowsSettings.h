#pragma once
#include "CoreMinimal.h"
#include "GamePvEBindingVowsSettings.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGamePvEBindingVowsSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BindingVowsIdArray;
    
    FGamePvEBindingVowsSettings();
};

