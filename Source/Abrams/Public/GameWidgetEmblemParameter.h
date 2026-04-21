#pragma once
#include "CoreMinimal.h"
#include "GameWidgetEmblemParameter.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetEmblemParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* EmblemIconTexture;
    
    FGameWidgetEmblemParameter();
};

