#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TickableInterface.h"
#include "GameTextManager.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class ABRAMS_API AGameTextManager : public AActor, public ITickableInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DebugTextDataTable;
    
public:
    AGameTextManager(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

