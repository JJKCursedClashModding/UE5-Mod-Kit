#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "GameKeyboardList.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameKeyboardList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FKey> KeyArray;
    
    FGameKeyboardList();
};

