#pragma once
#include "CoreMinimal.h"
#include "Animation/PoseSnapshot.h"
#include "Animation/SkeletalMeshActor.h"
#include "SequencerActorInterface.h"
#include "AbramsSequencerSkeletalMeshActor.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API AAbramsSequencerSkeletalMeshActor : public ASkeletalMeshActor, public ISequencerActorInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* OutlineAnimInstanceClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseSnapshot PoseSnapshot;
    
public:
    AAbramsSequencerSkeletalMeshActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FPoseSnapshot GetPoseSnapshot();
    

    // Fix for true pure virtual functions not being implemented
};

