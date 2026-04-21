#pragma once
#include "CoreMinimal.h"
#include "GameCollectionTileViewBase.h"
#include "GameCollectionArchiveTileWidget.generated.h"

class UGameCollectionArchiveDetailWidget;
class UGameCollectionArchiveItem;
class UGameItemDescriptionTextWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionArchiveTileWidget : public UGameCollectionTileViewBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionArchiveDetailWidget* DetailWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameItemDescriptionTextWidget* DescriptionWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameCollectionArchiveItem*> ItemList;
    
public:
    UGameCollectionArchiveTileWidget();

};

