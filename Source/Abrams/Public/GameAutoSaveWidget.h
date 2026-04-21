#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameAutoSaveWidget.generated.h"

class UGameWidgetBase;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameAutoSaveWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetBase* AutoSaveIconImage;
    
public:
    UGameAutoSaveWidget();

};

