#include "GameCharacterCaptureWidget.h"

UGameCharacterCaptureWidget::UGameCharacterCaptureWidget() {
    this->CaptureType = EGameCharacterCaptureType::Invalid;
    this->CharacterIndex = -1;
    this->CharacterImage = NULL;
    this->OverrideMaterialInstance = NULL;
}


