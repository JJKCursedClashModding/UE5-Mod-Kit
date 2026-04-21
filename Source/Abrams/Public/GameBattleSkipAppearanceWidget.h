#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameBattleSkipAppearanceWidget.generated.h"

class UGameInputGuideButtonWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSkipAppearanceWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameInputGuideButtonWidget* SkipButton;
    
public:
    UGameBattleSkipAppearanceWidget();

};

