#include "GameStoryCharaGraphWidget.h"

UGameStoryCharaGraphWidget::UGameStoryCharaGraphWidget() {
    this->LineHeightAdjustRate = 0.45f;
    this->LineTilingUnitSize = 230.00f;
    this->GraphInterpolateTime = 0.20f;
    this->FreeCursorInhaleStartDistance = 100.00f;
    this->FreeCursorInhaleEndDistance = 30.00f;
    this->FreeCursorInhaleIntensity = 0.40f;
    this->ReleaseFocusInterpolateTime = 0.50f;
    this->ReleaseFocusExpansionMag = 1.25f;
    this->ReleaseListWidgetMoveHeight = -150.00f;
    this->GraphCanvas = NULL;
    this->FreeCursor = NULL;
    this->ListWidget = NULL;
}


