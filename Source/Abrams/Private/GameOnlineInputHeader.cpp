#include "GameOnlineInputHeader.h"

FGameOnlineInputHeader::FGameOnlineInputHeader() {
    this->FrameNumber = 0;
    this->Ping = 0.00f;
    this->NextInputDelayCount = 0;
    this->NextInputDelayCountUseFrameNumber = 0;
    this->SkipAppearanceFrameNumber = 0;
    this->SkipAppearanceUserNum = 0;
}

