#pragma once
#include "CoreMinimal.h"
#include "GameWidgetCursedObjectsParameter.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetCursedObjectsParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CursedObjectsTexture;
    
    FGameWidgetCursedObjectsParameter();
};

