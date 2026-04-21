#include "GameBattleLockonDirectionWidget.h"

UGameBattleLockonDirectionWidget::UGameBattleLockonDirectionWidget() {
    this->LockonDirectionActorClass = NULL;
    this->EmissiveIntensity = 1.00f;
    this->LockonDirectionActor = NULL;
}

void UGameBattleLockonDirectionWidget::SetScaleOffset(const FVector& InScaleOffset) {
}

void UGameBattleLockonDirectionWidget::SetLocationOffset(const FVector& InLocationOffset) {
}

void UGameBattleLockonDirectionWidget::SetEmissiveIntensity(const float InEmissiveIntensity) {
}

void UGameBattleLockonDirectionWidget::SetActorColor(const FColor& InActorColor) {
}

FVector UGameBattleLockonDirectionWidget::GetScaleOffset() const {
    return FVector{};
}

FVector UGameBattleLockonDirectionWidget::GetLocationOffset() const {
    return FVector{};
}

float UGameBattleLockonDirectionWidget::GetEmissiveIntensity() const {
    return 0.0f;
}

FColor UGameBattleLockonDirectionWidget::GetActorColor() const {
    return FColor{};
}


