#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryChapterSelectWidget.generated.h"

class UCanvasPanel;
class UGameWidgetButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryChapterSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* ScrollPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* LeftButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* RightButton;
    
public:
    UGameStoryChapterSelectWidget();

};

