#pragma once
#include "CoreMinimal.h"
#include "GameWidgetCursedToolsParameter.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetCursedToolsParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CursedToolsTexture;
    
    FGameWidgetCursedToolsParameter();
};

