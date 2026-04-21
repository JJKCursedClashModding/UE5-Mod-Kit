#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameOnlineDebugCharacterData.h"
#include "GameOnlineDebugFrameData.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineDebugFrameData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineDebugCharacterData CharacterData[6];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime SendTime;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RandomStreamSeed[2];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomStreamRand[2];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FrameNumber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeLimit;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 DestructibleObjectNum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDiffCheckEnabled;
    
    ABRAMS_API FGameOnlineDebugFrameData();
};

