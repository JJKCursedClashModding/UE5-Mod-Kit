#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugGridActor.generated.h"

class UProceduralMeshComponent;

UCLASS(Blueprintable)
class FRAMEWORK_API ADebugGridActor : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralMeshComponent* Grid;
    
public:
    ADebugGridActor(const FObjectInitializer& ObjectInitializer);

};

