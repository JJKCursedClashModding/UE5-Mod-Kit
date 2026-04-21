#include "GameWidgetAnimationDelegate.h"

UGameWidgetAnimationDelegate::UGameWidgetAnimationDelegate() {
    this->OnPreOpenAnimationName = TEXT("OnPreOpen");
    this->OnPostOpenAnimationName = TEXT("OnPostOpen");
    this->OnPreCloseAnimationName = TEXT("OnPreClose");
    this->OnPostCloseAnimationName = TEXT("OnPostClose");
}


