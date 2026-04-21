#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryDlcChapterBackgroundWidget.generated.h"

class UGameMovieWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryDlcChapterBackgroundWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMovieWidget* MovieWidget;
    
public:
    UGameStoryDlcChapterBackgroundWidget();

};

