#pragma once
#include "CoreMinimal.h"
#include "SequencerManager.h"
#include "GameSequencerManager.generated.h"

class AActor;
class UAnimSequence;
class UGameSequencerLoadingParameter;
class UGameSequencerOffsetParameter;

UCLASS(Blueprintable)
class ABRAMS_API AGameSequencerManager : public ASequencerManager {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameSequencerLoadingParameter* LoadingParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameSequencerOffsetParameter* OffsetParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UAnimSequence*> AnimSequenceMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, AActor*> NPCMap;
    
public:
    AGameSequencerManager(const FObjectInitializer& ObjectInitializer);

};

