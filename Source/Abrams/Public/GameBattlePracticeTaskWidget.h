#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattlePracticeTaskWidget.generated.h"

class UGameWidgetInputGuideText;
class UGameWidgetRichTextBlock;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattlePracticeTaskWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* TaskDetailText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputGuideText* CommandText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* DegreeOfProgressText;
    
public:
    UGameBattlePracticeTaskWidget();

};

