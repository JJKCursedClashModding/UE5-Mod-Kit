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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryTopWidget* StoryTopWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryChapterSelectWidget* StoryChapterSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryMissionSelectWidget* StoryMissionSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryDlcChapterSelectWidget* StoryDlcChapterSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryDlcChapterBackgroundWidget* StoryDlcChapterBackgroundWidget;
    
public:
    UGameStoryWidget();

};

