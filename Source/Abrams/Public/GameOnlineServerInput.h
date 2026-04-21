#pragma once
#include "CoreMinimal.h"
#include "GameOnlineServerInput.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineServerInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FrameNumber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> InputFrameData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> DebugFrameData;
    
    ABRAMS_API FGameOnlineServerInput();
};

