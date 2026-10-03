#pragma once

#include "CoreMinimal.h"
#include "MovieSceneTrackEditor.h"

/**
 * Minimal Sequencer track editor for the game's custom sequencer tracks.
 *
 * The modkit reconstruction does not ship the game's original track editors, so opening
 * any animation that contains a custom Abrams track hit:
 *   checkf(TrackEditor, "Unable to find a track editor for track type ...")  (Sequencer.cpp:677)
 * This stub claims every USequencerTrackBase-derived track class so Sequencer can build
 * its outliner rows; sections use the generic FSequencerSection.
 * See Saved/uncooker_investigation_report.md (finding F4).
 */
class FAbramsSequencerStubTrackEditor : public FMovieSceneTrackEditor
{
public:
    explicit FAbramsSequencerStubTrackEditor(TSharedRef<ISequencer> InSequencer)
        : FMovieSceneTrackEditor(MoveTemp(InSequencer))
    {
    }

    static TSharedRef<ISequencerTrackEditor> CreateTrackEditor(TSharedRef<ISequencer> InSequencer)
    {
        return MakeShareable(new FAbramsSequencerStubTrackEditor(InSequencer));
    }

    //~ ISequencerTrackEditor
    virtual bool SupportsType(TSubclassOf<UMovieSceneTrack> TrackClass) const override;
};
