#include "GameAnimNotify_AutoHoming.h"

UGameAnimNotify_AutoHoming::UGameAnimNotify_AutoHoming() {
    this->Speed = 0.00f;
    this->BlendExp = 2.00f;
    this->RotationSpeed = 0.00f;
    this->AngleZ = 0.00f;
    this->bMoveForward = false;
    this->bZEnabled = true;
    this->bMoveOnlyZ = false;
    this->bPushEnabled = true;
}


