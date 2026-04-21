#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameMovieActor.generated.h"

class UManaPlayer;

UCLASS(Blueprintable)
class ABRAMS_API AGameMovieActor : public AGameActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UManaPlayer*> ManaPlayer;
    
public:
    AGameMovieActor(const FObjectInitializer& ObjectInitializer);

};

