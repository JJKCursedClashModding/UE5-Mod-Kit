#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameStaticMeshComponent.generated.h"

class UMaterialInstance;
class UMaterialInterface;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameStaticMeshComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstance*> SwapMaterialList;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMaterialInterface*, UMaterialInterface*> SwapMaterialMap;
    
public:
    UGameStaticMeshComponent(const FObjectInitializer& ObjectInitializer);

};

