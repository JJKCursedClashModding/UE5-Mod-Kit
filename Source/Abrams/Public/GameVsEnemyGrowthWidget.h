#pragma once
#include "CoreMinimal.h"
#include "GameWidgetRecyclerListView.h"
#include "GameVsEnemyGrowthWidget.generated.h"

class UGameCommonBackgroundBlurWidget;
class UGameVsEnemyGrowthDialogWidget;
class UGameVsEnemyGrowthLevelUpWidget;
class UGameVsEnemyGrowthListItemData;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyGrowthWidget : public UGameWidgetRecyclerListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyGrowthDialogWidget* DialogWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyGrowthLevelUpWidget* LevelUpWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonBackgroundBlurWidget* BlurWidget;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameVsEnemyGrowthListItemData*> ItemDataArray;
    
public:
    UGameVsEnemyGrowthWidget();

};

