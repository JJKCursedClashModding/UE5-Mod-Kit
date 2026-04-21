#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GameWidgetVsPlayerBattleModeButton.generated.h"

class UGameVsPlayerBattleModeAnimationWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetVsPlayerBattleModeButton : public UGameWidgetButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsPlayerBattleModeAnimationWidget* AnimationWidget_A;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsPlayerBattleModeAnimationWidget* AnimationWidget_B;
    
public:
    UGameWidgetVsPlayerBattleModeButton();

};

