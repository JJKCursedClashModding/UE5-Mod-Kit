#pragma once
#include "CoreMinimal.h"
#include "WidgetButton.h"
#include "WidgetListItem.h"
#include "DebugWidgetListViewContent.generated.h"

class UImage;
class UOverlay;
class UTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetListViewContent : public UWidgetButton, public IWidgetListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* ButtonText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* BackgroundImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Overlay;
    
public:
    UDebugWidgetListViewContent();


    // Fix for true pure virtual functions not being implemented
};

