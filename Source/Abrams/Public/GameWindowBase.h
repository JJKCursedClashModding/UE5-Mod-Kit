#pragma once
#include "CoreMinimal.h"
#include "WindowBase.h"
#include "GameWidgetChangeFocusedWindow.h"
#include "GameWidgetInputGuide.h"
#include "GameWidgetMappingInputReceive.h"
#include "GameWidgetResolution.h"
#include "GameWindowBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameWindowBase : public UWindowBase, public IGameWidgetInputGuide, public IGameWidgetMappingInputReceive, public IGameWidgetChangeFocusedWindow, public IGameWidgetResolution {
    GENERATED_BODY()
public:
    UGameWindowBase();


    // Fix for true pure virtual functions not being implemented
};

