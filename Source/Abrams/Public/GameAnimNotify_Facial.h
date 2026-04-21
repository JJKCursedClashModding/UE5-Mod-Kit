#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterFacial.h"
#include "GameAnimNotify.h"
#include "GameAnimNotify_Facial.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_Facial : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterFacial Facial;
    
    UGameAnimNotify_Facial();

};

