#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleAdaptIconWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetRichTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleAdaptIconWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetRichTextBlock* ButtonGuideText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* Extra_CP_110;
    
public:
    UGameBattleAdaptIconWidget();

};

