#pragma once
#include "CoreMinimal.h"
#include "ActorManager.h"
#include "GameEffectManager.generated.h"

class UMaterialParameterCollection;

UCLASS(Blueprintable)
class ABRAMS_API AGameEffectManager : public AActorManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
public:
    AGameEffectManager(const FObjectInitializer& ObjectInitializer);

};

