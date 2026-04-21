#include "GameStoryDemoMultiRichTextBlockWidget.h"

UGameStoryDemoMultiRichTextBlockWidget::UGameStoryDemoMultiRichTextBlockWidget() {
    this->SizeBox = NULL;
    this->DisplayRichTextBlock1 = NULL;
    this->DisplayRichTextBlock2 = NULL;
    this->DisplayRichTextBlock3 = NULL;
    this->DisplayRichTextBlock4 = NULL;
    this->DisplayRichTextBlock5 = NULL;
    this->DisplayRichTextBlock6 = NULL;
    this->DisplayRichTextBlock7 = NULL;
    this->DisplayRichTextBlock8 = NULL;
    this->DisplayRichTextBlock9 = NULL;
    this->Spacer1 = NULL;
    this->Spacer2 = NULL;
    this->Spacer3 = NULL;
    this->Spacer4 = NULL;
    this->Spacer5 = NULL;
    this->Spacer6 = NULL;
    this->Spacer7 = NULL;
    this->Spacer8 = NULL;
    this->BackgroundImage = NULL;
    this->LineBackgroundImage = NULL;
    this->LimitWidth = 0.00f;
    this->JustifyType = ETextJustify::Left;
    this->bRightAlignment = false;
    this->SpaceHeight = 1.00f;
    this->LimitLine = 6;
    this->ParseProcessor = NULL;
}


