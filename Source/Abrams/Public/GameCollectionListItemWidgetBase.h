#pragma once
#include "CoreMinimal.h"
#include "GameWidgetScrollListItem.h"
#include "GameWidgetTextButton.h"
#include "GameCollectionListItemWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionListItemWidgetBase : public UGameWidgetTextButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
    UGameCollectionListItemWidgetBase();


    // Fix for true pure virtual functions not being implemented
};

