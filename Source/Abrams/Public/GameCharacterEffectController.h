#pragma once
#include "CoreMinimal.h"
#include "GameActorEffectController.h"
#include "GameCharacterEffectController.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterEffectController : public UGameActorEffectController {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraComponent*> ResidentEffectArray;
    
public:
    UGameCharacterEffectController();

};

