#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameNPC.generated.h"

class UGameNPCMaterialController;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameNPC : public AGameActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameNPCMaterialController* MaterialController;
    
public:
    AGameNPC(const FObjectInitializer& ObjectInitializer);

};

