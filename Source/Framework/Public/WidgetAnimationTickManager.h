#pragma once
#include "CoreMinimal.h"
#include "Animation/UMGSequenceTickManager.h"
#include "WidgetAnimationTickManager.generated.h"

UCLASS(Blueprintable)
class FRAMEWORK_API UWidgetAnimationTickManager : public UUMGSequenceTickManager {
    GENERATED_BODY()
public:
    UWidgetAnimationTickManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

