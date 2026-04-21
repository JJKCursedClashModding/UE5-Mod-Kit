#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameBattleSettingsWidget.generated.h"

class UGameBattleSettingsInputBlockWidget;
class UGameOutGameTimeLimitWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSettingsWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameOutGameTimeLimitWidget* TimeLimitWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSettingsInputBlockWidget* InputBlockWindow;
    
public:
    UGameBattleSettingsWidget();

};

