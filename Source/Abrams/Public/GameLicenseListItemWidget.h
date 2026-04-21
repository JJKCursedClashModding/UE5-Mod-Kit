#pragma once
#include "CoreMinimal.h"
#include "GameWidgetScrollListItem.h"
#include "GameWidgetTextButton.h"
#include "GameLicenseListItemWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLicenseListItemWidget : public UGameWidgetTextButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
    UGameLicenseListItemWidget();


    // Fix for true pure virtual functions not being implemented
};

