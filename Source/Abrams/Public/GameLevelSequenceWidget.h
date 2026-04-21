#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLevelSequenceWidget.generated.h"

class UGameLevelSequenceStoryDemoCenterSubtitleWidget;
class UGameLevelSequenceStoryDemoLogoWidget;
class UGameLevelSequenceStoryDemoSubtitleWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLevelSequenceWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameLevelSequenceStoryDemoLogoWidget* StoryDemoLogo_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameLevelSequenceStoryDemoLogoWidget* StoryDemoLogo_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameLevelSequenceStoryDemoSubtitleWidget* StoryDemoSubtitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameLevelSequenceStoryDemoCenterSubtitleWidget* StoryDemoCenterSubtitle;
    
public:
    UGameLevelSequenceWidget();

};

