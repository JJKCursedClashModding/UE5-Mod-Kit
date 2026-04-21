#pragma once
#include "CoreMinimal.h"
#include "Components/DirectionalLightComponent.h"
#include "AbramsSequencerDirectionalLightComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMSSEQUENCER_API UAbramsSequencerDirectionalLightComponent : public UDirectionalLightComponent {
    GENERATED_BODY()
public:
    UAbramsSequencerDirectionalLightComponent(const FObjectInitializer& ObjectInitializer);

};

