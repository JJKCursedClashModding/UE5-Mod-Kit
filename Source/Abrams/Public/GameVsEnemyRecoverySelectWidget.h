#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVsEnemyRecoverySelectWidget.generated.h"

class UGameVsEnemyIntervalForceGaugeWidget;
class UGameVsEnemyRecoveryCharacterWidget;
class UGameVsEnemyRecoveryHealPointTextWidget;
class UGameVsEnemyRecoveryInputAnimationWidget;
class UGameVsEnemyRecoveryInputBlockWidget;
class UGameWidgetButton;
class UGameWidgetVsEnemyRecoverySelectButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyRecoverySelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyRecoveryCharacterWidget* CharacterWidget_1P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyRecoveryCharacterWidget* CharacterWidget_2P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVsEnemyRecoverySelectButton* CostHealButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyRecoveryInputAnimationWidget* CostHealInputAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyIntervalForceGaugeWidget* ForceGaugeWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetButton* ExitButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyRecoveryHealPointTextWidget* HealPointText_1P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyRecoveryHealPointTextWidget* HealPointText_2P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyRecoveryInputBlockWidget* InputBlockWidget;
    
public:
    UGameVsEnemyRecoverySelectWidget();

};

