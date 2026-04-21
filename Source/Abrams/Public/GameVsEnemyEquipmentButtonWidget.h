#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameWidgetButton.h"
#include "GameVsEnemyEquipmentButtonWidget.generated.h"

class UGameCommonLockIconWidget;
class UGameEquipmentItemIconWidget;
class UGameWidgetFrame;
class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyEquipmentButtonWidget : public UGameWidgetButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ReleasedFrameColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor UnreleasedFrameColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameEquipmentItemIconWidget* EquipmentItemIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* EquipmentEmptyIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonLockIconWidget* EquipmentLockIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* EquipmentLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetFrame* FrameWidget;
    
public:
    UGameVsEnemyEquipmentButtonWidget();

};

