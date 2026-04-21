#pragma once
#include "CoreMinimal.h"
#include "GameAnimNS.h"
#include "GameAnimNS_FaceLookAtActiveChange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ABRAMS_API UGameAnimNS_FaceLookAtActiveChange : public UGameAnimNS {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActive;
    
    UGameAnimNS_FaceLookAtActiveChange();

};

