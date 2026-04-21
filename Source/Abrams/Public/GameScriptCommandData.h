#pragma once
#include "CoreMinimal.h"
#include "GameScriptCommandData.generated.h"

USTRUCT(BlueprintType)
struct FGameScriptCommandData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CommandName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Arguments;
    
    ABRAMS_API FGameScriptCommandData();
};

