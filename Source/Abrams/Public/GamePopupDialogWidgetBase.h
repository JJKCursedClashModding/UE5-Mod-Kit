#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GamePopupDialogWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGamePopupDialogWidgetBase : public UGameWindowBase {
    GENERATED_BODY()
public:
    UGamePopupDialogWidgetBase();

};

