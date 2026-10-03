#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVsEnemyEquipmentSettingsWidget.generated.h"

class UGameVsEnemyEquipmentButtonWidget;
class UGameVsEnemyEquipmentSelectTileViewWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyEquipmentSettingsWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyEquipmentButtonWidget* EquipmentSlotButton_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyEquipmentButtonWidget* EquipmentSlotButton_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyEquipmentButtonWidget* EquipmentSlotButton_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyEquipmentSelectTileViewWidget* EquipmentSelectWidget;
    
public:
    UGameVsEnemyEquipmentSettingsWidget();

};

