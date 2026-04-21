#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterIndex.h"
#include "EGameOnlinePvEIntervalAction.h"
#include "GameOnlinePvEIntervalAction.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlinePvEIntervalAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterIndex CharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameOnlinePvEIntervalAction Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BindingVowsArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDecide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnd;
    
    ABRAMS_API FGameOnlinePvEIntervalAction();
};

