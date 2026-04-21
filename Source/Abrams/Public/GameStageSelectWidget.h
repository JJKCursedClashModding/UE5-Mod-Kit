#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "StageItemParameter.h"
#include "GameStageSelectWidget.generated.h"

class UGameStageSelectListItemData;
class UGameStageSelectListViewWidget;
class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStageSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FStageItemParameter> StageItemParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStageSelectListViewWidget* StageList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* StageNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* StageImage;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameStageSelectListItemData*> ListItemDataArray;
    
public:
    UGameStageSelectWidget();

};

