#include "WidgetNoPixelSnappingTextBlock.h"

UWidgetNoPixelSnappingTextBlock::UWidgetNoPixelSnappingTextBlock() {
    this->bIsVariable = false;
    this->MinDesiredWidth = 0.00f;
    this->bWrapWithInvalidationPanel = false;
    this->TextTransformPolicy = ETextTransformPolicy::None;
    this->TextOverflowPolicy = ETextOverflowPolicy::Clip;
    this->bSimpleTextMode = false;
}

void UWidgetNoPixelSnappingTextBlock::SetTextTransformPolicy(ETextTransformPolicy InTransformPolicy) {
}

void UWidgetNoPixelSnappingTextBlock::SetTextOverflowPolicy(ETextOverflowPolicy InOverflowPolicy) {
}

void UWidgetNoPixelSnappingTextBlock::SetText(FText InText) {
}

void UWidgetNoPixelSnappingTextBlock::SetStrikeBrush(FSlateBrush InStrikeBrush) {
}

void UWidgetNoPixelSnappingTextBlock::SetShadowOffset(FVector2D InShadowOffset) {
}

void UWidgetNoPixelSnappingTextBlock::SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity) {
}

void UWidgetNoPixelSnappingTextBlock::SetOpacity(float InOpacity) {
}

void UWidgetNoPixelSnappingTextBlock::SetMinDesiredWidth(float InMinDesiredWidth) {
}

void UWidgetNoPixelSnappingTextBlock::SetFontOutlineMaterial(UMaterialInterface* InMaterial) {
}

void UWidgetNoPixelSnappingTextBlock::SetFontMaterial(UMaterialInterface* InMaterial) {
}

void UWidgetNoPixelSnappingTextBlock::SetFont(FSlateFontInfo InFontInfo) {
}

void UWidgetNoPixelSnappingTextBlock::SetColorAndOpacity(FSlateColor InColorAndOpacity) {
}

void UWidgetNoPixelSnappingTextBlock::SetAutoWrapText(bool InAutoTextWrap) {
}

FText UWidgetNoPixelSnappingTextBlock::GetText() const {
    return FText::GetEmpty();
}

UMaterialInstanceDynamic* UWidgetNoPixelSnappingTextBlock::GetDynamicOutlineMaterial() {
    return NULL;
}

UMaterialInstanceDynamic* UWidgetNoPixelSnappingTextBlock::GetDynamicFontMaterial() {
    return NULL;
}


