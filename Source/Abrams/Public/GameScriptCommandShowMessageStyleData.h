#pragma once
#include "CoreMinimal.h"
#include "GameScriptCommandShowMessageStyleData.generated.h"

USTRUCT(BlueprintType)
struct FGameScriptCommandShowMessageStyleData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TextStyleName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LineSpace;
    
    ABRAMS_API FGameScriptCommandShowMessageStyleData();
};

