#pragma once
#include "CoreMinimal.h"
#include "GameWidgetOperationParameter.generated.h"

class UPaperSprite;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetOperationParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPaperSprite* OperationSprite;
    
    FGameWidgetOperationParameter();
};

