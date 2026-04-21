#pragma once
#include "CoreMinimal.h"
#include "GameConfigItemScrollWidget.h"
#include "GameConfigGameWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameConfigGameWidget : public UGameConfigItemScrollWidget {
    GENERATED_BODY()
public:
    UGameConfigGameWidget();

};

