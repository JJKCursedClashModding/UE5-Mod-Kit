#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionArchiveContent.generated.h"

UENUM(BlueprintType)
enum class EGameCollectionArchiveContent : uint8 {
    None,
    CursedTools,
    CursedObjects,
    Extras,
    Costumes,
    Pose,
    DecorationPlates,
    Titles,
    Nicknames,
    Emblems,
    Movies,
};

