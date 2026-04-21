#pragma once
#include "CoreMinimal.h"
#include "EGameLevelSequenceRecordingMediaType.generated.h"

UENUM()
enum class EGameLevelSequenceRecordingMediaType : uint32 {
    None,
    Video,
    TransformInfo,
    All = 4294967295,
};
