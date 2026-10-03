#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryCharaRelateWidget.generated.h"

class UGameStoryCharaRelateDetailWidget;
class UGameStoryCharaRelateTargetListItemData;
class UGameStoryCharaRelateTargetListViewWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryCharaRelateWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateTargetListViewWidget* TargetListViewWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameStoryCharaRelateDetailWidget* DetailWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameStoryCharaRelateTargetListItemData*> TargetListItemDataArray;
    
public:
    UGameStoryCharaRelateWidget();

};

