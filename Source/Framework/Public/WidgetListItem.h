#pragma once
#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "WidgetListItem.generated.h"

UINTERFACE()
class UWidgetListItem : public UUserObjectListEntry {
    GENERATED_BODY()
};

class IWidgetListItem : public IUserObjectListEntry {
    GENERATED_BODY()
public:
};

