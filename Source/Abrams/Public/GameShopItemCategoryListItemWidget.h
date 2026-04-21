#pragma once
#include "CoreMinimal.h"
#include "GameWidgetTabWindowContent.h"
#include "GameShopItemCategoryListItemWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameShopItemCategoryListItemWidget : public UGameWidgetTabWindowContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CategoryImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* NewBadgeImage;
    
public:
    UGameShopItemCategoryListItemWidget();

};

