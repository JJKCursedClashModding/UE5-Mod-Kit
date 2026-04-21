#include "GameWidgetScrollListView.h"
#include "Layout/Clipping.h"

UGameWidgetScrollListView::UGameWidgetScrollListView() {
    this->Clipping = EWidgetClipping::ClipToBounds;
    this->EntryWidgetClass = NULL;
    this->ColumnCount = 1;
    this->EntrySpace = 0.00f;
    this->ColumnEntrySpace = 0.00f;
    this->HorizontalAlignment = HAlign_Fill;
    this->VerticalAlignment = VAlign_Fill;
    this->PreCreateItemCount = 0;
    this->bItemNavigationEnabled = true;
    this->InvalidNavigationScrollOffset = 0.00f;
    this->bAutoFitEnabled = true;
    this->ScrollBox = NULL;
}


