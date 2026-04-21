#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameBattleSettingsBackgroundWidget.generated.h"

class UGameCharacterCaptureWidget;
class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSettingsBackgroundWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BackgroundImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* CharacterImage;
    
public:
    UGameBattleSettingsBackgroundWidget();

};

