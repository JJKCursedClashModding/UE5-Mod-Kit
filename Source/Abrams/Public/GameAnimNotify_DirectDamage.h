#pragma once
#include "CoreMinimal.h"
#include "GameAnimNotify.h"
#include "GameAnimNotify_DirectDamage.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_DirectDamage : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_Damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ImpactPointBoneName;
    
    UGameAnimNotify_DirectDamage();

};

