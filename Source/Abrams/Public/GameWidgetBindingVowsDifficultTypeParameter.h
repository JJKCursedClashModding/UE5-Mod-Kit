#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBindingVowsDifficultTypeParameter.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetBindingVowsDifficultTypeParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* MaskTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* FrameTexture;
    
    FGameWidgetBindingVowsDifficultTypeParameter();
};

