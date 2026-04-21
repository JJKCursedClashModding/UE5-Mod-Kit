#pragma once
#include "CoreMinimal.h"
#include "GameConfigItemScrollWidget.h"
#include "GameConfigTutorialWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameConfigTutorialWidget : public UGameConfigItemScrollWidget {
    GENERATED_BODY()
public:
    UGameConfigTutorialWidget();

};

