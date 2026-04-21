#pragma once
#include "CoreMinimal.h"
#include "GameCustomizeChatCommandWidget.h"
#include "GameWidgetScrollListItem.h"
#include "GameCustomizeChatTileItemWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCustomizeChatTileItemWidget : public UGameCustomizeChatCommandWidget, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
    UGameCustomizeChatTileItemWidget();


    // Fix for true pure virtual functions not being implemented
};

