#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryWidget.generated.h"

class UGameStoryChapterSelectWidget;
class UGameStoryDlcChapterBackgroundWidget;
class UGameStoryDlcChapterSelectWidget;
class UGameStoryMissionSelectWidget;
class UGameStoryTopWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryTopWidget* StoryTopWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryChapterSelectWidget* StoryChapterSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryMissionSelectWidget* StoryMissionSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryDlcChapterSelectWidget* StoryDlcChapterSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryDlcChapterBackgroundWidget* StoryDlcChapterBackgroundWidget;
    
public:
    UGameStoryWidget();

};

