#pragma once
#include "CoreMinimal.h"
#include "GameOnlinePvEBindingVows.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlinePvEBindingVows {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BindingVowsArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ABRAMS_API FGameOnlinePvEBindingVows();
};

