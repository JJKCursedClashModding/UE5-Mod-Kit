#pragma once
#include "CoreMinimal.h"
#include "GameFadeWidget.h"
#include "GameWindowBase.h"
#include "GameFrontFadeWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameFrontFadeWidget : public UGameWindowBase, public IGameFadeWidget {
    GENERATED_BODY()
public:
    UGameFrontFadeWidget();


    // Fix for true pure virtual functions not being implemented
};

