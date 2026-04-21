#pragma once
#include "CoreMinimal.h"
#include "GameDecalParameter.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSpawnDecalSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSpawnDecalSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DecalId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameDecalParameter DecalParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DecalSortOrder;
    
    UAbramsSequencerSpawnDecalSection();

};

