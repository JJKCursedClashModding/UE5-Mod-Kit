#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneStringChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerCreateSnapshotSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerCreateSnapshotSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneStringChannel Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MeshReferenceTargetActorTag;
    
    UAbramsSequencerCreateSnapshotSection();

};

