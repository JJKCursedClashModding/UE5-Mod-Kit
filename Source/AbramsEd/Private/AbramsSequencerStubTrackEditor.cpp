#include "AbramsSequencerStubTrackEditor.h"

#include "MovieSceneTrack.h"
#include "SequencerTrackBase.h"

bool FAbramsSequencerStubTrackEditor::SupportsType(TSubclassOf<UMovieSceneTrack> TrackClass) const
{
    return TrackClass && TrackClass->IsChildOf(USequencerTrackBase::StaticClass());
}
