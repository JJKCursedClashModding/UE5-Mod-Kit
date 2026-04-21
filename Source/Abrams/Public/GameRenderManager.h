#pragma once
#include "CoreMinimal.h"
#include "RenderManager.h"
#include "EGameRenderPostProcessMaterial.h"
#include "GameRenderManager.generated.h"

class AGameDestructibleMesh;
class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class ABRAMS_API AGameRenderManager : public ARenderManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameRenderPostProcessMaterial, UMaterialInstanceDynamic*> PostProcessMaterialMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGameDestructibleMesh*> DestructibleMeshArray;
    
public:
    AGameRenderManager(const FObjectInitializer& ObjectInitializer);

};

