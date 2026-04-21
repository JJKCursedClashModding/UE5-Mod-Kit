#pragma once
#include "CoreMinimal.h"
#include "GameConfigItemScrollWidget.h"
#include "GameConfigSoundVolumeWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameConfigSoundVolumeWidget : public UGameConfigItemScrollWidget {
    GENERATED_BODY()
public:
    UGameConfigSoundVolumeWidget();

};

