#pragma once
#include "CoreMinimal.h"
#include "GameWidgetScrollListView.h"
#include "GameCollectionListViewBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionListViewBase : public UGameWidgetScrollListView {
    GENERATED_BODY()
public:
    UGameCollectionListViewBase();

};

