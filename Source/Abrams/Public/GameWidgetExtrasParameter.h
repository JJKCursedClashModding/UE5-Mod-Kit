#pragma once
#include "CoreMinimal.h"
#include "GameWidgetExtrasParameter.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetExtrasParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ExtrasTexture;
    
    FGameWidgetExtrasParameter();
};

