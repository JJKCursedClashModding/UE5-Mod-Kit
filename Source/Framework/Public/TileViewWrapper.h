#pragma once
#include "CoreMinimal.h"
#include "Components/TileView.h"
#include "TileViewWrapper.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API UTileViewWrapper : public UTileView {
    GENERATED_BODY()
public:
    UTileViewWrapper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

