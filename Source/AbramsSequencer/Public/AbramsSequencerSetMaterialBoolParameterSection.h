#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerMaterialBoolParameterName.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSetMaterialBoolParameterSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetMaterialBoolParameterSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel Value;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerMaterialBoolParameterName ParameterName;
    
    UAbramsSequencerSetMaterialBoolParameterSection();

};

