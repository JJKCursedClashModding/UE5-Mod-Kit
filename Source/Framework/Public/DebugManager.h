#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugManager.generated.h"

class ADebugGridActor;

UCLASS(Blueprintable)
class FRAMEWORK_API ADebugManager : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADebugGridActor* Grid;
    
public:
    ADebugManager(const FObjectInitializer& ObjectInitializer);

};

