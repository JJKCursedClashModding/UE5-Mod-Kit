#pragma once
#include "CoreMinimal.h"
#include "GameWidgetScrollListItem.h"
#include "GameWidgetTextButton.h"
#include "GameCustomizeCardTileItemWidget.generated.h"

class UCanvasPanel;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCustomizeCardTileItemWidget : public UGameWidgetTextButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* NewPanel;
    
public:
    UGameCustomizeCardTileItemWidget();


    // Fix for true pure virtual functions not being implemented
};

