#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterIndex.h"
#include "GameOnlineInputFrameData.h"
#include "GameOnlineInputData.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineInputData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineInputFrameData FrameDataArray[32];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterIndex CharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ABRAMS_API FGameOnlineInputData();
};

