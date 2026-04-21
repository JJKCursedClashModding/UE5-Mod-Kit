#pragma once
#include "CoreMinimal.h"
#include "WidgetProgressBar.h"
#include "GameWidgetProgressBar.generated.h"

class UWidget;

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetProgressBar : public UWidgetProgressBar {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumShowRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* ConstraintWidget;
    
public:
    UGameWidgetProgressBar();

};

