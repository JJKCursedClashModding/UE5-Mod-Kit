#pragma once
#include "CoreMinimal.h"
#include "GameNPC.h"
#include "GameSequencerNPCActorInterface.h"
#include "SequencerActorInterface.h"
#include "AbramsSequencerNPCActor.generated.h"

class UGameAnimInstance;
class UGamePostProcessAnimInstance;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerNPCActor : public AGameNPC, public ISequencerActorInterface, public IGameSequencerNPCActorInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NPCId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParentCharacterId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameAnimInstance* AnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGamePostProcessAnimInstance* PostProcessAnimInstance;
    
public:
    AAbramsSequencerNPCActor(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

