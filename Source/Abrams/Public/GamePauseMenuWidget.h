#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GamePauseMenuWidget.generated.h"

class UGamePauseMenuLayoutWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGamePauseMenuWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGamePauseMenuLayoutWidget* PauseMenuLayout;
    
public:
    UGamePauseMenuWidget();

};

