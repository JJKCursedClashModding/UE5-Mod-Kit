#pragma once
#include "CoreMinimal.h"
#include "GameOnlineInputHeader.h"
#include "GameOnlineClientInput.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineClientInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameOnlineInputHeader Header;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> InputBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> DebugBody;
    
    ABRAMS_API FGameOnlineClientInput();
};

