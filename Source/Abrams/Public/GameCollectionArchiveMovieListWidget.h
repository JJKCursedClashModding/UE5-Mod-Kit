#pragma once
#include "CoreMinimal.h"
#include "GameCollectionListViewBase.h"
#include "GameCollectionArchiveMovieListWidget.generated.h"

class UGameCollectionArchiveItem;
class UPaperSprite;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionArchiveMovieListWidget : public UGameCollectionListViewBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameCollectionArchiveItem*> ItemList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPaperSprite*> MovieThumbnailImage;
    
public:
    UGameCollectionArchiveMovieListWidget();

};

