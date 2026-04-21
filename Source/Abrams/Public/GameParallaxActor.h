#pragma once
#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "GameParallaxActor.generated.h"

class UMaterialInstance;

UCLASS(Blueprintable)
class ABRAMS_API AGameParallaxActor : public ADecalActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* MaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotationScaleX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotationScaleY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotationScaleZ;
    
public:
    AGameParallaxActor(const FObjectInitializer& ObjectInitializer);

};

