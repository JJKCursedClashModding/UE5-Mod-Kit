#pragma once
#include "CoreMinimal.h"
#include "ESequencerTrackType.generated.h"

UENUM(BlueprintType)
enum class ESequencerTrackType : uint8 {
    Invalid,
    BaseTrack,
    MasterBaseTrack,
    BindingBaseTrack,
    MasterTrack,
    BindingTrack,
};

