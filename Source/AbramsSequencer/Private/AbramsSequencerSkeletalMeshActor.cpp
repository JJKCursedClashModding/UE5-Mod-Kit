#include "AbramsSequencerSkeletalMeshActor.h"

AAbramsSequencerSkeletalMeshActor::AAbramsSequencerSkeletalMeshActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OutlineAnimInstanceClass = NULL;
}

FPoseSnapshot AAbramsSequencerSkeletalMeshActor::GetPoseSnapshot() {
    return FPoseSnapshot{};
}


