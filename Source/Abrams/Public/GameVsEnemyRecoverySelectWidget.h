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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyRecoveryCharacterWidget* CharacterWidget_1P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyRecoveryCharacterWidget* CharacterWidget_2P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyRecoverySelectButton* CostHealButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyRecoveryInputAnimationWidget* CostHealInputAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyIntervalForceGaugeWidget* ForceGaugeWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* ExitButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyRecoveryHealPointTextWidget* HealPointText_1P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyRecoveryHealPointTextWidget* HealPointText_2P;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyRecoveryInputBlockWidget* InputBlockWidget;
    
public:
    UGameVsEnemyRecoverySelectWidget();

};

