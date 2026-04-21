#pragma once
#include "CoreMinimal.h"
#include "GameVirtualCamera.h"
#include "GameCharacterVirtualCamera.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterVirtualCamera : public UGameVirtualCamera {
    GENERATED_BODY()
public:
    UGameCharacterVirtualCamera();

};

