#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionMasterBase.h"
#include "AbramsSequencerSetNearClipPlaneSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetNearClipPlaneSection : public UAbramsSequencerSectionMasterBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel NearClip;
    
    UAbramsSequencerSetNearClipPlaneSection();

};

