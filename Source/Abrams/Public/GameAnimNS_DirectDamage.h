#pragma once
#include "CoreMinimal.h"
#include "GameAnimNS.h"
#include "GameAnimNS_DirectDamage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ABRAMS_API UGameAnimNS_DirectDamage : public UGameAnimNS {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_Damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ImpactPointBoneName;
    
    UGameAnimNS_DirectDamage();

};

