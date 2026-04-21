#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "SequencerActorInterface.h"
#include "AbramsSequencerParallaxMaterialActor.generated.h"

class UCurveFloat;
class UDecalComponent;
class UMaterialInstance;
class UMaterialInstanceDynamic;
class USceneComponent;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerParallaxMaterialActor : public AActor, public ISequencerActorInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 X;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Y;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Z;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDecalComponent* Decal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* MaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* OpacityTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* EmissiveTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MaterialInstanceDynamic;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeline Timeline;
    
public:
    AAbramsSequencerParallaxMaterialActor(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnUpdateOpacityTimer(const float Output);
    
    UFUNCTION(BlueprintCallable)
    void OnUpdateEmissiveTimer(const float Output);
    

    // Fix for true pure virtual functions not being implemented
};

