#pragma once
#include "CoreMinimal.h"
#include "GameCollectionListNewItemWidget.h"
#include "GameCollectionArchiveMovieItemWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionArchiveMovieItemWidget : public UGameCollectionListNewItemWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ChapterText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ItemImage;
    
public:
    UGameCollectionArchiveMovieItemWidget();

};

