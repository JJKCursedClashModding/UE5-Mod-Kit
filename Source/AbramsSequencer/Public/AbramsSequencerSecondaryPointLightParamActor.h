#pragma once
#include "CoreMinimal.h"
#include "SequencerActorBase.h"
#include "AbramsSequencerSecondaryPointLightParamActor.generated.h"

class UMaterialParameterCollection;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerSecondaryPointLightParamActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialParameterCollection*> ParameterCollections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUseMulti;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
public:
    AAbramsSequencerSecondaryPointLightParamActor(const FObjectInitializer& ObjectInitializer);

};

