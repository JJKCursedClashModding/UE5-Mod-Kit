#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Styling/SlateBrush.h"
#include "GameWidgetRichTextBlockImageRow.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetRichTextBlockImageRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush Brush;
    
    FGameWidgetRichTextBlockImageRow();
};

