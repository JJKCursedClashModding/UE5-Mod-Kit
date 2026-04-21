#pragma once
#include "CoreMinimal.h"
#include "WidgetWorldTickable.h"
#include "GameWidgetButton.h"
#include "GameCharacterSelectContentButtonWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCharacterSelectContentButtonWidget : public UGameWidgetButton, public IWidgetWorldTickable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsePeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimePeriod;
    
public:
    UGameCharacterSelectContentButtonWidget();


    // Fix for true pure virtual functions not being implemented
};

