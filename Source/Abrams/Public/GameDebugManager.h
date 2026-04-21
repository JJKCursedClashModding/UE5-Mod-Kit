#pragma once
#include "CoreMinimal.h"
#include "DebugManager.h"
#include "GameDebugManager.generated.h"

class UGameDebugParameter;

UCLASS(Blueprintable)
class ABRAMS_API AGameDebugManager : public ADebugManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameDebugParameter* DebugParameter;
    
public:
    AGameDebugManager(const FObjectInitializer& ObjectInitializer);

};

