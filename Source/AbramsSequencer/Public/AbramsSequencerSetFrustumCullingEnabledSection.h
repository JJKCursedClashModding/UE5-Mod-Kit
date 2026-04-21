#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSetFrustumCullingEnabledSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetFrustumCullingEnabledSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel bEnabled;
    
    UAbramsSequencerSetFrustumCullingEnabledSection();

};

