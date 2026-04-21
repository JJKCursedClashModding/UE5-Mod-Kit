#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterFacialPartsEyes.h"
#include "GameAnimNotify.h"
#include "GameAnimNotify_FacialPartsEyes.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_FacialPartsEyes : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterFacialPartsEyes FacialPartsEyes;
    
    UGameAnimNotify_FacialPartsEyes();

};

