#pragma once
#include "CoreMinimal.h"
#include "GameWidgetInputGuide.h"
#include "GameWidgetRichTextBlock.h"
#include "GameWidgetInputGuideText.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetInputGuideText : public UGameWidgetRichTextBlock, public IGameWidgetInputGuide {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSmallIcon;
    
public:
    UGameWidgetInputGuideText();


    // Fix for true pure virtual functions not being implemented
};

