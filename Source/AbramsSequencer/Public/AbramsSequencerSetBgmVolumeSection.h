#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSetBgmVolumeSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetBgmVolumeSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel Volume;
    
    UAbramsSequencerSetBgmVolumeSection();

};

