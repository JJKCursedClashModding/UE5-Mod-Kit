#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputManager.generated.h"

class UForceFeedbackEffect;

UCLASS(Blueprintable)
class FRAMEWORK_API AInputManager : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UForceFeedbackEffect*> ForceFeedbackEffectArray;
    
public:
    AInputManager(const FObjectInitializer& ObjectInitializer);

};

