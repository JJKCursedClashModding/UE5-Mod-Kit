#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSetOverrideMaterialInstanceSection.generated.h"

class UMaterialInstance;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetOverrideMaterialInstanceSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMaterialInstance*, UMaterialInstance*> OverrideMaterialMap;
    
    UAbramsSequencerSetOverrideMaterialInstanceSection();

};

