#pragma once
#include "CoreMinimal.h"
#include "GameAnimNS.h"
#include "GameAnimNS_MontagePlayRate.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ABRAMS_API UGameAnimNS_MontagePlayRate : public UGameAnimNS {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNotifyEndInitializePlayRateEnabled;
    
    UGameAnimNS_MontagePlayRate();

};

