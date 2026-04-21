#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameConfigCategoryWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameConfigCategoryWidgetBase : public UGameWindowBase {
    GENERATED_BODY()
public:
    UGameConfigCategoryWidgetBase();

};

