#pragma once
#include "CoreMinimal.h"
#include "EGameInputKey.h"
#include "GameWidgetButton.h"
#include "GameWidgetInputImageButton.generated.h"

class UGameWidgetInputImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetInputImageButton : public UGameWidgetButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* InputImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameInputKey InputKey;
    
public:
    UGameWidgetInputImageButton();

};

