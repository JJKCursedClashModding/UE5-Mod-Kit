#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameBattleLockonDirectionActor.generated.h"

class UGameBattleLockonDirectionMaterialController;
class UNiagaraComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameBattleLockonDirectionActor : public AGameActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameBattleLockonDirectionMaterialController* MaterialController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraComponent*> NiagaraComponentArray;
    
public:
    AGameBattleLockonDirectionActor(const FObjectInitializer& ObjectInitializer);

};

