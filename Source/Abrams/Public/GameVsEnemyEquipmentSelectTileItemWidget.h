#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameWidgetButton.h"
#include "GameWidgetScrollListItem.h"
#include "GameVsEnemyEquipmentSelectTileItemWidget.generated.h"

class UGameCommonLockIconWidget;
class UGameEquipmentItemIconWidget;
class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyEquipmentSelectTileItemWidget : public UGameWidgetButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DisabledIconColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameEquipmentItemIconWidget* EquipmentItemIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* EquippedImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* NewImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonLockIconWidget* LockIcon;
    
public:
    UGameVsEnemyEquipmentSelectTileItemWidget();


    // Fix for true pure virtual functions not being implemented
};

