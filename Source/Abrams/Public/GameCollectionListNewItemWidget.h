#pragma once
#include "CoreMinimal.h"
#include "GameCollectionListItemWidgetBase.h"
#include "GameCollectionListNewItemWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionListNewItemWidget : public UGameCollectionListItemWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* NewImage;
    
public:
    UGameCollectionListNewItemWidget();

};

