#pragma once
#include "CoreMinimal.h"
#include "LegacyCameraShake.h"
#include "GameCameraShake.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCameraShake : public ULegacyCameraShake {
    GENERATED_BODY()
public:
    UGameCameraShake();

};

