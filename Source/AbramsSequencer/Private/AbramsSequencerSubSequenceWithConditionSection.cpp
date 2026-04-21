#include "AbramsSequencerSubSequenceWithConditionSection.h"

UAbramsSequencerSubSequenceWithConditionSection::UAbramsSequencerSubSequenceWithConditionSection(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    // PrerollTime was removed from UMovieSceneSubSection in UE 5.1
    this->ConditionType = EGameSequencerSubSequenceConditionType::None;
    this->platform = 0;
}

