#pragma once
#include "CoreMinimal.h"
#include "GameWidgetFontLanguageParameter.generated.h"

class UFont;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetFontLanguageParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFont* ThickFont;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFont* RegularFont;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFont* ThinFont;
    
    FGameWidgetFontLanguageParameter();
};

