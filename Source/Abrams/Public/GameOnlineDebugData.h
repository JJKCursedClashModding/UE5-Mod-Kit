#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterIndex.h"
#include "GameOnlineDebugFrameData.h"
#include "GameOnlineDebugData.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineDebugData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineDebugFrameData FrameDataArray[16];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterIndex CharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ABRAMS_API FGameOnlineDebugData();
};

