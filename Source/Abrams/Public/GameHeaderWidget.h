#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameHeaderWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameHeaderWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* HeaderText;
    
public:
    UGameHeaderWidget();

};

