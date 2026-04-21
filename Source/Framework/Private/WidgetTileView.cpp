#include "WidgetTileView.h"

UWidgetTileView::UWidgetTileView() {
    this->TileView = NULL;
    this->EntryHeight = 128.00f;
    this->EntryWidth = 128.00f;
    this->TileAlignment = EListItemAlignment::EvenlyDistributed;
    this->bWrapHorizontalNavigation = true;
}


