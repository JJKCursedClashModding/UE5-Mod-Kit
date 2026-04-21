#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameCharacterBrain.generated.h"

class UGameCharacterBehaviorController;

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterBrain : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameCharacterBehaviorController* BehaviorController;
    
public:
    UGameCharacterBrain();

};

