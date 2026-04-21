#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameConfigSubWidget.generated.h"

class UGameConfigCategoryWidgetBase;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameConfigSubWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameConfigCategoryWidgetBase* BrightnessConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameConfigCategoryWidgetBase* KeyConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameConfigCategoryWidgetBase* Tutorial;
    
public:
    UGameConfigSubWidget();

};

