#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameAnimNS.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ABRAMS_API UGameAnimNS : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UGameAnimNS();

};

