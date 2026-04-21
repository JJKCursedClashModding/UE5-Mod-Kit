#pragma once
#include "CoreMinimal.h"
#include "GameAnimNotify.h"
#include "GameAnimNotify_UniqueAction.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_UniqueAction : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Parameter_Int;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Parameter_Float;
    
    UGameAnimNotify_UniqueAction();

};

