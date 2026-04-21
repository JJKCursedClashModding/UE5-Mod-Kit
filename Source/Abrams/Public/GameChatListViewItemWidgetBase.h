#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GameWidgetScrollListItem.h"
#include "GameChatListViewItemWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameChatListViewItemWidgetBase : public UGameWidgetButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
    UGameChatListViewItemWidgetBase();


    // Fix for true pure virtual functions not being implemented
};

