#include "GameBattleForceGaugeIconWidget.h"

UGameBattleForceGaugeIconWidget::UGameBattleForceGaugeIconWidget() {
    this->NoiseIntensity = 0.10f;
    this->SizeCanvas = NULL;
    this->IconImage = NULL;
}

void UGameBattleForceGaugeIconWidget::OnDisappearanceFinished(const FName& InAnimationName) {
}


