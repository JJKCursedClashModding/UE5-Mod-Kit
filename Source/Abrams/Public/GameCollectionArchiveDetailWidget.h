#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameCollectionArchiveDetailWidget.generated.h"

class UGameItemIconWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionArchiveDetailWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameItemIconWidget* ItemImage;
    
public:
    UGameCollectionArchiveDetailWidget();

};

