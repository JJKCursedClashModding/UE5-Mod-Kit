#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameActor.h"
#include "HideDebrisObjectData.h"
#include "GameDebrisObject.generated.h"

class AGameDestructibleObject;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameDebrisObject : public AGameActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HideEffectId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HideEffectOffsetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HideEffectScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HideSoundEffectId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReceivesDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGameDestructibleObject*> ShowReactionDestructibleObjectArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FHideDebrisObjectData> HideReactionDestructibleObjectArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipShowReaction;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> StaticMeshArray;
    
public:
    AGameDebrisObject(const FObjectInitializer& ObjectInitializer);

};

