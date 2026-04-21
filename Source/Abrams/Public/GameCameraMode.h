#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameCameraMode.generated.h"

UCLASS(Abstract, Blueprintable)
class ABRAMS_API UGameCameraMode : public UObject {
    GENERATED_BODY()
public:
    UGameCameraMode();

};

