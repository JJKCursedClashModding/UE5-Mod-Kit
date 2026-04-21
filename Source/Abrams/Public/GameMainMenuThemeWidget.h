#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameMainMenuThemeWidget.generated.h"

class UGameMainMenuThemeListView;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameMainMenuThemeWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuThemeListView* MainMenuThemeList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* MainMenuThemeText;
    
public:
    UGameMainMenuThemeWidget();

};

