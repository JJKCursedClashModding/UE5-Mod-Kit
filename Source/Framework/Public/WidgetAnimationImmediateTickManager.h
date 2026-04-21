#pragma once
#include "CoreMinimal.h"
#include "Animation/UMGSequenceTickManager.h"
#include "WidgetAnimationImmediateTickManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API UWidgetAnimationImmediateTickManager : public UUMGSequenceTickManager {
    GENERATED_BODY()
public:
    UWidgetAnimationImmediateTickManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

