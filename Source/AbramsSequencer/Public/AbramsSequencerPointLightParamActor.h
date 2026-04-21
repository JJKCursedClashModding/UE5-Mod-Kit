#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SequencerActorBase.h"
#include "AbramsSequencerPointLightParamActor.generated.h"

class UMaterialParameterCollection;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerPointLightParamActor : public ASequencerActorBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialParameterCollection*> ParameterCollections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Attenuation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor LightColor;
    
public:
    AAbramsSequencerPointLightParamActor(const FObjectInitializer& ObjectInitializer);

};

