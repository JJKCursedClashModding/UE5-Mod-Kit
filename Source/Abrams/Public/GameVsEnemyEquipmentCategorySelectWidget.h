#pragma once
#include "CoreMinimal.h"
#include "GameWidgetTabWindow.h"
#include "GameVsEnemyEquipmentCategorySelectWidget.generated.h"

class UGameInputGuideButtonWidget;
class UGameShopItemCategoryListItemWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyEquipmentCategorySelectWidget : public UGameWidgetTabWindow {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* AllTabButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* CursedToolsTabButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* CursedObjectsTabButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameShopItemCategoryListItemWidget* ExtrasTabButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameInputGuideButtonWidget* InputGuideLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameInputGuideButtonWidget* InputGuideRight;
    
public:
    UGameVsEnemyEquipmentCategorySelectWidget();

};

