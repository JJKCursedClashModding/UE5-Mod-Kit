#pragma once
#include "CoreMinimal.h"
#include "GameWidgetPaginationListView.h"
#include "GameCollectionArchiveTextListWidget.generated.h"

class UGameCollectionArchiveItem;
class UGameItemDescriptionTextWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionArchiveTextListWidget : public UGameWidgetPaginationListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameItemDescriptionTextWidget* DescriptionWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameCollectionArchiveItem*> NicknameItemList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameCollectionArchiveItem*> TitleItemList;
    
public:
    UGameCollectionArchiveTextListWidget();

};

