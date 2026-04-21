#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryTopWidget.generated.h"

class UGameStoryTopButtonWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryTopWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryTopButtonWidget* ChapterButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryTopButtonWidget* CorrelationDiagramButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryTopButtonWidget* DlcChapterButton;
    
public:
    UGameStoryTopWidget();

};

