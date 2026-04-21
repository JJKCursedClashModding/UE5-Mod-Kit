#pragma once
#include "CoreMinimal.h"
#include "GameFadeWidget.h"
#include "GameWindowBase.h"
#include "GameBackFadeWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameBackFadeWidget : public UGameWindowBase, public IGameFadeWidget {
    GENERATED_BODY()
public:
    UGameBackFadeWidget();


    // Fix for true pure virtual functions not being implemented
};

