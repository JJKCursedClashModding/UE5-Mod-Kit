#pragma once
#include "CoreMinimal.h"
#include "GameBattleTransitionWidgetBase.h"
#include "GameBattleStartMissionWaveWidget.generated.h"

class UCanvasPanel;
class UGameWidgetRichTextBlock;
class UOverlay;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleStartMissionWaveWidget : public UGameBattleTransitionWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* WaveTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* OrderTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* OrderTextCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Subtext_Group_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Subtext_Group_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* FinalWaveCanvas;
    
public:
    UGameBattleStartMissionWaveWidget();

};

