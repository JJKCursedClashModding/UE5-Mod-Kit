#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerMaterialScalarParameterName.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSetMaterialScalarParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetMaterialScalarParameterSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel Value;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerMaterialScalarParameterName ParameterName;
    
    UAbramsSequencerSetMaterialScalarParameterSection();

};

