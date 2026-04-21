#pragma once
#include "CoreMinimal.h"
#include "GameBattlePostProcessEffectWidgetBase.h"
#include "GameBattlePostProcessLoopEffectWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattlePostProcessLoopEffectWidgetBase : public UGameBattlePostProcessEffectWidgetBase {
    GENERATED_BODY()
public:
    UGameBattlePostProcessLoopEffectWidgetBase();

private:
    UFUNCTION(BlueprintCallable)
    void OnOpenAnimationFinished_Internal(const FName& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    void OnCloseAnimationFinished_Internal(const FName& AnimationName);
    
};

