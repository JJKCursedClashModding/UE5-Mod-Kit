#pragma once
#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "GameDecalActor.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable)
class ABRAMS_API AGameDecalActor : public ADecalActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* MobileMaterial;
    
public:
    AGameDecalActor(const FObjectInitializer& ObjectInitializer);

};

