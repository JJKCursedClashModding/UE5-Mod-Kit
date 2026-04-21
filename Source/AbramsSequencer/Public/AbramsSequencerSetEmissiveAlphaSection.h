#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSetEmissiveAlphaSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetEmissiveAlphaSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel Alpha;
    
    UAbramsSequencerSetEmissiveAlphaSection();

};

