#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVsEnemyBindingVowsSelectWidget.generated.h"

class UGameWidgetInputGuideText;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyBindingVowsSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetInputGuideText* BuffText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetInputGuideText* DebuffText;
    
public:
    UGameVsEnemyBindingVowsSelectWidget();

};

