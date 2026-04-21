#pragma once
#include "CoreMinimal.h"
#include "WidgetTransitionable.h"
#include "GameWidgetBase.h"
#include "GameItemThumbnailWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameItemThumbnailWidget : public UGameWidgetBase, public IWidgetTransitionable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ItemThumbnailImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ItemThumbnailWatermarkImage;
    
public:
    UGameItemThumbnailWidget();


    // Fix for true pure virtual functions not being implemented
};

