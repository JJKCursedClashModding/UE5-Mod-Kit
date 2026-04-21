#include "AbramsSequencerPlayAnimSequenceFromConverterSection.h"

UAbramsSequencerPlayAnimSequenceFromConverterSection::UAbramsSequencerPlayAnimSequenceFromConverterSection() {
    this->AnimSequence = NULL;
    this->SlotNodeName = TEXT("DefaultSlot");
    this->BlendIn = -1.00f;
    this->BlendOut = -1.00f;
    this->PlayRate = 1.00f;
    this->FirstLoopPlayStartTime = 0.00f;
    this->StartTimeOffset = 0.00f;
    this->EndTimeOffset = 0.00f;
    this->LoopCount = 1;
    this->bEnableAutoBlendOut = true;
    this->BlendOutTriggerTime = 0.00f;
}


