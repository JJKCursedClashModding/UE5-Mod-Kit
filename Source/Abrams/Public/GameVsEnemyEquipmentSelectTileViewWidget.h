#pragma once
#include "CoreMinimal.h"
#include "GameWidgetRecyclerListView.h"
#include "GameVsEnemyEquipmentSelectTileViewWidget.generated.h"

class UGameItemDescriptionTextWidget;
class UGameVsEnemyEquipmentCategorySelectWidget;
class UGameVsEnemyEquipmentSelectTileItemData;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyEquipmentSelectTileViewWidget : public UGameWidgetRecyclerListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyEquipmentCategorySelectWidget* CategorySelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameItemDescriptionTextWidget* ItemDescriptionText;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameVsEnemyEquipmentSelectTileItemData*> ItemDataArray;
    
public:
    UGameVsEnemyEquipmentSelectTileViewWidget();

};

