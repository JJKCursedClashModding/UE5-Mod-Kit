#pragma once
#include "CoreMinimal.h"
#include "Components/SizeBox.h"
#include "GameWidgetSafeArea.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetSafeArea : public USizeBox {
    GENERATED_BODY()
public:
    UGameWidgetSafeArea();

};

