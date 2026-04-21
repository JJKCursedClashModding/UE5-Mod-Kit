#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerMapDataType.generated.h"

UENUM(BlueprintType)
enum class EGameSequencerMapDataType : uint8 {
    UseCustomTrackParam,
    RefrenceCurrentLevel,
    MAP_01,
    MAP_02,
    MAP_03,
    MAP_04,
    MAP_05,
    MAP_06,
    MAP_07,
    MAP_08,
    MAP_09,
    MAP_10,
    DEM_01,
    DEM_02,
    VLM_01,
    SDM_10,
    SRM_10,
    SRM_20,
};

