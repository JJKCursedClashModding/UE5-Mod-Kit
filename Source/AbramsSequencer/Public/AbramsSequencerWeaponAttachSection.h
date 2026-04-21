#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerSectionBindingBase.h"
#include "AbramsSequencerWeaponAttachSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerWeaponAttachSection : public UAbramsSequencerSectionBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachSocketName;
    
    UAbramsSequencerWeaponAttachSection();

};

