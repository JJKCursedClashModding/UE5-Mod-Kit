#pragma once
#include "CoreMinimal.h"
#include "GameCapsuleComponent.h"
#include "GameCollisionParameterInterface.h"
#include "GameCapsuleComponent_EffectAttack.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameCapsuleComponent_EffectAttack : public UGameCapsuleComponent, public IGameCollisionParameterInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreDestructibleObjectHitEnabled;
    
    UGameCapsuleComponent_EffectAttack(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

