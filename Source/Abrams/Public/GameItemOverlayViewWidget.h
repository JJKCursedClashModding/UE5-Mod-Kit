#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameItemOverlayViewWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameItemOverlayViewWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ItemImage;
    
public:
    UGameItemOverlayViewWidget();

};

