#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameLevelObject.generated.h"

class UGameLevelObjectMaterialController;

UCLASS(Blueprintable)
class ABRAMS_API AGameLevelObject : public AGameActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameLevelObjectMaterialController* MaterialController;
    
public:
    AGameLevelObject(const FObjectInitializer& ObjectInitializer);

};

