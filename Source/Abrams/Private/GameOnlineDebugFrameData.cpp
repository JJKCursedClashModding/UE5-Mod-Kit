#include "GameOnlineDebugFrameData.h"

FGameOnlineDebugFrameData::FGameOnlineDebugFrameData() {
    this->RandomStreamSeed[0] = 0;
    this->RandomStreamSeed[1] = 0;
    this->RandomStreamRand[0] = 0.00f;
    this->RandomStreamRand[1] = 0.00f;
    this->FrameNumber = 0;
    this->TimeLimit = 0.00f;
    this->DestructibleObjectNum = 0;
    this->bDiffCheckEnabled = false;
}

