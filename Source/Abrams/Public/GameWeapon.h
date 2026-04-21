#pragma once
#include "CoreMinimal.h"
#include "GameActor.h"
#include "GameWeapon.generated.h"

class UGameWeaponMaterialController;
class UMeshComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameWeapon : public AGameActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWeaponMaterialController* MaterialController;
    
public:
    AGameWeapon(const FObjectInitializer& ObjectInitializer);

};

