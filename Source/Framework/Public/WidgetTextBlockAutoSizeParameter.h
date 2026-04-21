#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EWidgetTextBlockAutoSizeType.h"
#include "WidgetTextBlockAutoSizeParameter.generated.h"

USTRUCT(BlueprintType)
struct FWidgetTextBlockAutoSizeParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWidgetTextBlockAutoSizeType AutoSizeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxFontSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinFontSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D AutoFitSize;
    
    FRAMEWORK_API FWidgetTextBlockAutoSizeParameter();
};

