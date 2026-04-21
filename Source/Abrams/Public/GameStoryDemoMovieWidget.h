#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryDemoMovieWidget.generated.h"

class UGameMovieWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryDemoMovieWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMovieWidget* MovieWidget;
    
public:
    UGameStoryDemoMovieWidget();

};

