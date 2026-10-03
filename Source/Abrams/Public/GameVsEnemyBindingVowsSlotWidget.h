#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameVsEnemyBindingVowsSlotWidget.generated.h"

class UGameBindingVowsWidget;
class UGameWidgetImage;
class UOverlay;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyBindingVowsSlotWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBindingVowsWidget* BindingVows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* EmptySlotImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* EmptySlotImage_Lock;
    
public:
    UGameVsEnemyBindingVowsSlotWidget();

};

