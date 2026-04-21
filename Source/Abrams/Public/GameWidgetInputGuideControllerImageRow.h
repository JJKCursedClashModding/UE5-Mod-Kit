#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EInputKey.h"
#include "Styling/SlateBrush.h"
#include "GameWidgetInputGuideControllerImageRow.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetInputGuideControllerImageRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputKey InputKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush Brush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush SmallBrush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush TinyBrush;
    
    FGameWidgetInputGuideControllerImageRow();
};

