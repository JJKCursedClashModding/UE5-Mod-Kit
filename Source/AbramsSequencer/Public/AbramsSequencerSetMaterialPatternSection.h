#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneIntegerChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSetMaterialPatternSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetMaterialPatternSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneIntegerChannel Pattern;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetParameter;
    
    UAbramsSequencerSetMaterialPatternSection();

};

