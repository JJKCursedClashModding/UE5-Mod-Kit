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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* ButtonGuideText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Extra_CP_110;
    
public:
    UGameBattleAdaptIconWidget();

};

