#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLevelSequenceStoryDemoSubtitleWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLevelSequenceStoryDemoSubtitleWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* Subtitle;
    
public:
    UGameLevelSequenceStoryDemoSubtitleWidget();

};

