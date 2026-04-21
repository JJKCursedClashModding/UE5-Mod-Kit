#pragma once
#include "CoreMinimal.h"
#include "WidgetEditableText.h"
#include "GameWidgetEditableText.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetEditableText : public UWidgetEditableText {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DescriptionTextId;
    
    UGameWidgetEditableText();

};

