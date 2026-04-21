#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "AbramsSequencerDirectionalLightActor.generated.h"

class UAbramsSequencerDirectionalLightComponent;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerDirectionalLightActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAbramsSequencerDirectionalLightComponent* DirectionalLight;
    
public:
    AAbramsSequencerDirectionalLightActor(const FObjectInitializer& ObjectInitializer);

};

