#pragma once
#include "CoreMinimal.h"
#include "EGameStoryTopMenu.generated.h"

UENUM(BlueprintType)
enum class EGameStoryTopMenu : uint8 {
    None,
    Back,
    ChapterSelect,
    DlcChapterSelect,
    CorrelationDiagram,
};

