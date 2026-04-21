#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GameAnimNotify.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify : public UAnimNotify {
    GENERATED_BODY()
public:
    UGameAnimNotify();

};

