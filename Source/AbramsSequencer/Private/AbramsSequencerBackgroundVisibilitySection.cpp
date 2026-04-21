#include "AbramsSequencerBackgroundVisibilitySection.h"

UAbramsSequencerBackgroundVisibilitySection::UAbramsSequencerBackgroundVisibilitySection() {
    this->bContainedMain = false;
    this->bContainedEnvironment = false;
    this->bContainedLevelDesign = true;
    this->bContainedLightBuild = true;
    this->bContainedFog = false;
    this->bContainedPostProcessVolume = false;
}


