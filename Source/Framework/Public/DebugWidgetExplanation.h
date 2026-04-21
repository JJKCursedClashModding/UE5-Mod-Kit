#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugWidgetExplanation.generated.h"

class UDebugWidgetExplanationTextBlock;
class UImage;

UCLASS(Blueprintable, EditInlineNew)
class FRAMEWORK_API UDebugWidgetExplanation : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* FrameImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetExplanationTextBlock* TextBlock;
    
public:
    UDebugWidgetExplanation();

};

