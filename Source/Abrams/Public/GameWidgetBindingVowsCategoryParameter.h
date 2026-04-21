#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBindingVowsCategoryParameter.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetBindingVowsCategoryParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CategoryTexture;
    
    FGameWidgetBindingVowsCategoryParameter();
};

