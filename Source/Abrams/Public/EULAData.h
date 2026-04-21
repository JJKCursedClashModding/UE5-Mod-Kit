#pragma once
#include "CoreMinimal.h"
#include "EApplicationLanguage.h"
#include "EULAData.generated.h"

USTRUCT(BlueprintType)
struct FEULAData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EApplicationLanguage, int32> PlatformData;
    
    ABRAMS_API FEULAData();
};

