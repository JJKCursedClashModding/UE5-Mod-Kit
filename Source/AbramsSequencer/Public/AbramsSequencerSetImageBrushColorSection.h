#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionUMGBindingBase.h"
#include "AbramsSequencerSetImageBrushColorSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetImageBrushColorSection : public UAbramsSequencerSectionUMGBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel R;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel G;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel B;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel A;
    
    UAbramsSequencerSetImageBrushColorSection();

};

