#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterCaptureType.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSceneCaptureCharacterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSceneCaptureCharacterSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel bCaptureEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetCharacterTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterCaptureType TargetCaptureType;
    
    UAbramsSequencerSceneCaptureCharacterSection();

};

