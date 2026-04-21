#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameCommandListPassiveWidget.generated.h"

class UGameWidgetRichTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCommandListPassiveWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* PassiveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* PassiveExplanation;
    
public:
    UGameCommandListPassiveWidget();

};

