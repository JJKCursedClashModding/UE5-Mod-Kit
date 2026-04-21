#pragma once
#include "CoreMinimal.h"
#include "GameWidgetRecyclerListView.h"
#include "GameCollectionTileViewBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionTileViewBase : public UGameWidgetRecyclerListView {
    GENERATED_BODY()
public:
    UGameCollectionTileViewBase();

};

