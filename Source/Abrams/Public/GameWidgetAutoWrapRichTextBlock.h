#pragma once
#include "CoreMinimal.h"
#include "GameWidgetRichTextBlock.h"
#include "GameWidgetAutoWrapRichTextBlock.generated.h"

class UGameWidgetAutoWrapParseProcessor;

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetAutoWrapRichTextBlock : public UGameWidgetRichTextBlock {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LimitWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetAutoWrapParseProcessor* ParseProcessor;
    
public:
    UGameWidgetAutoWrapRichTextBlock();

};

