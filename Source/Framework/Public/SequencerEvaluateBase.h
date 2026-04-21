#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "SequencerEvaluateBase.generated.h"

USTRUCT(BlueprintType)
struct FRAMEWORK_API FSequencerEvaluateBase : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    FSequencerEvaluateBase();
};

