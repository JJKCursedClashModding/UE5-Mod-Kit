#pragma once
#include "CoreMinimal.h"
#include "EGameCustomizeCharaViewItemType.generated.h"

UENUM(BlueprintType)
enum class EGameCustomizeCharaViewItemType : uint8 {
    None,
    Costume,
    Normal,
    Cursed,
    SituationOverviewPose,
    LoopMin = Costume,
    LoopMax = SituationOverviewPose,
};

